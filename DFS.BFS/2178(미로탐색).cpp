#include <iostream>
#include <queue>
using namespace std;

int N, M;
string miro[101];
int dist[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct info {
    int x, y;
};

void bfs(info n) {
    dist[n.x][n.y] = 1;
    queue<info> q;
    q.push({n.x, n.y});
    
    while(!q.empty()) {
        info cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            // 아래 조건문을 위로 올리면 OutOfBounds에러 왜냐, 위의 조건문 통과하지 않았으니까 ..
            if (dist[nx][ny] != -1 || miro[nx][ny] == '0') continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = -1;
        }
    }
    for (int i = 0 ; i < N; i++) {
        cin >> miro[i];
    }
    
    bfs({0, 0});
    cout << dist[N-1][M-1];
}
