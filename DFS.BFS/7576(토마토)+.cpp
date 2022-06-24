#include <iostream>
#include <queue>
using namespace std;

struct info {
    int x, y;
};

int N, M, ans;
int tmt[1001][1001];
int dist[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<info> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M ;j++) {
            dist[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tmt[i][j];
            if (tmt[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()) {
        info cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (dist[nx][ny] != -1 || tmt[nx][ny] != 0) continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == -1 && tmt[i][j] != -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}
