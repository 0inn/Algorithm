//
//  연습.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 6/13/24.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos {
    int x, y;
};

int n, m;
int board[501][501];
bool visited[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(Pos pos) {
    queue<Pos> q;
    q.push(pos);
    visited[pos.x][pos.y] = true;
    
    int wid = 1;
    
    while(!q.empty()) {
        Pos cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            
            if(nx<0 || ny<0 || nx>= n || ny >= m) continue;
            if(visited[nx][ny] || board[nx][ny] == 0) continue;
            
            q.push(Pos{nx, ny});
            visited[nx][ny] = true;
            wid++;
        }
    }
    
    return wid;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    
    int cnt = 0, maxWid = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j] || board[i][j] == 0) continue;
            maxWid = max(maxWid, bfs(Pos{i, j}));
            cnt++;
        }
    }
    
    cout << cnt << "\n" << maxWid;
}
