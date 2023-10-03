#include<iostream>
#include<queue>
#define x first
#define y second
#define MAX 101
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string color[MAX];
bool check[MAX][MAX];
bool check2[MAX][MAX];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> color[i];
	}

	int red = 0;
	int green = 0;
	int blue = 0;
	int rg = 0;
	
	// 빨강
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color[i][j] != 'R' || check[i][j])
				continue;
			red++;
			check[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i, j });
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (color[nx][ny] != 'R' || check[nx][ny])
						continue;
					check[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	// 초록
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color[i][j] != 'G' || check[i][j])
				continue;
			green++;
			check[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i, j });
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (color[nx][ny] != 'G' || check[nx][ny])
						continue;
					check[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	// 파랑
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color[i][j] != 'B' || check[i][j])
				continue;
			blue++;
			check[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i, j });
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (color[nx][ny] != 'B' || check[nx][ny])
						continue;
					check[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	// 빨+초
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color[i][j] == 'B' || check2[i][j])
				continue;
			rg++;
			check2[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i, j });
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (color[nx][ny] == 'B' || check2[nx][ny])
						continue;
					check2[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	cout << red + green + blue << " " << rg + blue;
}