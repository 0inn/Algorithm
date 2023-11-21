//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/22.
//

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 501

using namespace std;

struct point {
    int x, y;
};

int n, m, cnt, width;
int arr[MAX][MAX];
bool check[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void input() {
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
}

void bfs(point p) {
    queue<point> q;
    q.push({p});
    check[p.x][p.y] = true;
    
    int cur_width = 0;
    while(!q.empty()) {
        point cur = q.front();
        q.pop();
        cur_width++;
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(check[nx][ny] || arr[nx][ny] == 0) continue;
            
            q.push(point{nx, ny});
            check[nx][ny] = true;
        }
    }
    
    width = max(width, cur_width);
}

void find_pictures() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(check[i][j]) continue;
            if(arr[i][j] == 1) {
                bfs(point{i, j});
                cnt++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    find_pictures();
    cout << cnt << "\n" << width;
}
