//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/04.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 21
#define RAINBOW 0
#define BLACK -1
#define EMPTY -2
using namespace std;

struct Point {
    int x, y;
};

struct Info {
    Point st;
    int total_cnt, cnt;
    vector<Point> cur_blocks;
};

int N, M, ans;
vector<vector<int>> board;
bool check[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void print() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print_check() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << check[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void input() {
    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        vector<int> row;
        board.push_back(row);
        for(int j=0, n; j<N; j++) {
            cin >> n;
            board[i].push_back(n);
        }
    }
}

Info bfs(Point cur_p) {
    queue<Point> q;
    int cur_block = board[cur_p.x][cur_p.y];
    int total_cnt = 1, cnt = cur_block != RAINBOW ? 0 : 1;
    vector<Point> cur_blocks;
    
    check[cur_p.x][cur_p.y] = true;
    q.push(cur_p);
    cur_blocks.push_back(cur_p);
    
    while(!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(check[nx][ny] || board[nx][ny] == BLACK) continue;
            
            if(board[nx][ny] == RAINBOW) {
                cnt += 1;
                total_cnt += 1;
            }
            else if(board[nx][ny] == cur_block) total_cnt += 1;
            else continue;
            
            if(board[nx][ny] != RAINBOW && (cur_p.x > nx || (cur_p.x == nx && cur_p.y > ny))) {
                cur_p.x = nx;
                cur_p.y = ny;
            }
            check[nx][ny] = true;
            Point nxt = Point{nx, ny};
            q.push(nxt);
            cur_blocks.push_back(nxt);
        }
    }
    
    if(total_cnt < 2) return Info{Point{0, 0}, 0, 0, cur_blocks};
    return Info{cur_p, total_cnt, cnt, cur_blocks};
}

void remove_block(vector<Point> v) {
    for(int i=0; i<v.size(); i++) {
        int x = v[i].x;
        int y = v[i].y;
        board[x][y] = EMPTY;
    }
}

void gravity() {
    for(int i=0; i<N; i++) {
        queue<int> max_idx;
        for(int j=N-1; j>=0; j--) {
            if(board[j][i] == EMPTY) {
                max_idx.push(j);
                continue;
            }
            else if(board[j][i] == BLACK) {
                max_idx = queue<int>();
                continue;
            }
            else {
                if(max_idx.empty()) continue;
                
                int idx = max_idx.front();
                board[idx][i] = board[j][i];
                board[j][i] = EMPTY;
                max_idx.pop();
                max_idx.push(j);
            }
        }
    }
}

void turn() {
    vector<vector<int>> tmp = board;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tmp[N-j-1][i] = board[i][j];
        }
    }
    
    board = tmp;
}

void reset_check() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            check[i][j] = false;
        }
    }
}

void reset_rainbow_check() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == RAINBOW) check[i][j] = false;
        }
    }
}

void update_ans(int score) {
    ans += (score * score);
}

bool play_round() {
    vector<Point> v;
    Info max_result = Info {Point{0, 0}, 0, 0, v};
    
    reset_check();
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == BLACK || board[i][j] == EMPTY || board[i][j] == RAINBOW || check[i][j]) continue;
            reset_rainbow_check();
            Info result = bfs(Point{i, j});
            
            if(max_result.total_cnt < result.total_cnt) {
                max_result = result;
            } else if (max_result.total_cnt == result.total_cnt) {
                if(max_result.cnt < result.cnt) {
                    max_result = result;
                } else if(max_result.cnt == result.cnt) {
                    if(max_result.st.x < result.st.x) {
                        max_result = result;
                    } else if(max_result.st.x == result.st.x) {
                        if(max_result.st.y < result.st.y) {
                            max_result = result;
                        }
                    }
                }
            }
        }
    }
    
    remove_block(max_result.cur_blocks);
    update_ans(max_result.total_cnt);
    
    return max_result.total_cnt == 0 ? false : true;
}

void play() {
    while(play_round()) {
        gravity();
        turn();
        gravity();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    play();
    cout << ans;
}
