#include<bits/stdc++.h>
using namespace std;

struct q_tmt {
	int z, x, y;
};

int M, N, H;
int tmt[101][101][101];
int dist[101][101][101];
int dx[6] = { -1,0,1,0,0,0 };
int dy[6] = { 0,-1,0,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

// 익음(1) 안익음(0) 없음(-1)
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> M >> N >> H;
	queue<q_tmt> q;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tmt[h][i][j];
				if (tmt[h][i][j] == 1) q.push({ h,i,j });
				if (tmt[h][i][j] == 0) dist[h][i][j] = -1;
			}
		}
	}

	while (!q.empty()) {
		q_tmt cur = q.front();
		q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int nz = cur.z + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
			if (dist[nz][nx][ny] >= 0) continue;	// 토마토 안 익은 경우만 아래 계산
			dist[nz][nx][ny] = dist[cur.z][cur.x][cur.y] + 1;
			q.push({ nz,nx,ny });
		}
	}

	int ans = 0;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (dist[h][i][j] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[h][i][j]);
			}
		}
	}
	cout << ans;

	return 0;
}