//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/08/22.
//

#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

int N;
char arr[101][101];
bool check[101][101];
int ans[2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input() {
    cin >> N;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
}

void clear_check_arr() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            check[i][j] = false;
        }
    }
}

void bfs(int x, int y, bool isColor) {
    char color = arr[x][y];
    queue<Point> q;
    check[x][y] = true;
    q.push(Point{x, y});
    
    while(!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = dx[dir] + cur.x;
            int ny = dy[dir] + cur.y;
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N || check[nx][ny]) continue;
            
            if(arr[nx][ny] == color || (!isColor && color != 'B' && arr[nx][ny] != 'B')) {
                q.push(Point{nx, ny});
                check[nx][ny] = true;
            }
        }
    }
}

void cal_color(bool isColor) {
    int cnt = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!check[i][j]) {
                bfs(i, j, isColor);
                cnt++;
            }
        }
    }
    
    ans[isColor ? 0 : 1] = cnt;
}

void output() {
    cout << ans[0] << " " << ans[1] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    cal_color(true);
    clear_check_arr();
    cal_color(false);
    output();
}
