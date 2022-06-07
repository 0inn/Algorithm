#include<bits/stdc++.h>
using namespace std;

struct info {
	int x, y;
};

int N, M;
int ice[301][301];
int tmp[301][301];
bool check[301][301];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ice[i][j];
		}
	}

	int year = 0;
	while (true) {
		memset(check, false, sizeof(check));
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ice[i][j] == 0 || check[i][j]) continue;
				queue<info> icheck;
				icheck.push({ i,j });
				while (!icheck.empty()) {
					info cur = icheck.front();
					icheck.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
						if (ice[nx][ny] == 0 || check[nx][ny]) continue;
						icheck.push({ nx,ny });
						check[nx][ny] = true;
					}
				}
				cnt++;
			}
		}

		if (cnt == 0) {
			cout << 0;
			break;
		}

		if (cnt >= 2) {
			cout << year;
			break;
		}

		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ice[i][j] == 0) continue;
				int melt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (ice[nx][ny] != 0) continue;
					melt++;
				}
				if (ice[i][j] > melt) tmp[i][j] = ice[i][j] - melt;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				ice[i][j] = tmp[i][j];
			}
		}
		year++;
	}

	return 0;
}
