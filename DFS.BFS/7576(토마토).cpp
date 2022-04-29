//
//  7576(토마토).cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/04/29.
//

#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

struct info {
    int x, y;
};

int N, M, ans, fail;
int tmt[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
queue<info> q;

void bfs() {
    while(!q.empty()) {
        info cur = q.front();
        q.pop();
        ans = max(ans, dist[cur.x][cur.y]);
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tmt[i][j];
            if (tmt[i][j] == 1) q.push({i, j});
            if (tmt[i][j] == 0) dist[i][j] = -1;
        }
    }
    
    bfs();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
}
