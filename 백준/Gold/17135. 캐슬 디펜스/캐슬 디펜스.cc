//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/09/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

int N, M, D, total, ans;
int arr[16][16], tmp_arr[16][16];
int dist[16][16];
vector<Point> attacks;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void input() {
    cin >> N >> M >> D;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
            if(arr[i][j]) total++;
        }
    }
}

void bfs(Point start, int NL) {
    queue<Point> q;
    q.push(start);
    
    while(!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        if(dist[cur.x][cur.y] == D) break;
        for(int dir=0; dir<4; dir++) {
            Point nxt = Point{cur.x+dx[dir], cur.y+dy[dir]};
            if(nxt.x < 0 || nxt.y < 0 || nxt.x >= NL || nxt.y >= M) continue;
            if(dist[nxt.x][nxt.y] != -1) continue;
            if(tmp_arr[nxt.x][nxt.y] == 1) { // 적 제거한 경우
                attacks.push_back(nxt);
                return;
            }
            q.push(Point{nxt.x, nxt.y});
            dist[nxt.x][nxt.y] = dist[cur.x][cur.y] + 1;
        }
    }
}

void reset_dist() {
    for(int i=0; i<=N; i++) {
        for(int j=0; j<M; j++) {
            dist[i][j] = -1;
        }
    }
}

void reset_arr() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            tmp_arr[i][j] = arr[i][j];
        }
    }
}

int cal_score() {
    int cnt = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(tmp_arr[i][j] == 1) cnt++;
        }
    }
    
    return total-cnt;
}

void attack(vector<Point> army) {
    int game_over = N;
    
    while(game_over--) {
        for(int i=0; i<army.size(); i++) {
            reset_dist();
            dist[army[i].x][army[i].y] = 0;
            bfs(army[i], army[i].x);
        }
        
        for(int i=0; i<attacks.size(); i++) {
            tmp_arr[attacks[i].x][attacks[i].y] = 0;
        }
        attacks.clear();
        
        for(int j=0; j<army.size(); j++) {
            army[j].x--;
        }
    }
}

void start_game() {
    vector<Point> army;
    vector<bool> temp(M, true);
    
    for(int i=0; i<M-3; i++) {
        temp[i] = false;
    }
    
    do {
        for(int i=0; i<M; ++i) {
            if(temp[i]) {
                army.push_back(Point{N, i});
                dist[N][i] = 0;
            }
        }
        reset_arr();
        attack(army);
        ans = max(ans, cal_score());
        army.clear();
    } while(next_permutation(temp.begin(), temp.end()));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    start_game();
    cout << ans;
}
