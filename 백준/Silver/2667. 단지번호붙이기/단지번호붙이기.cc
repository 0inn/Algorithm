#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define x first
#define y second
#define MAX 26
using namespace std;

string map[MAX];
bool visit[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

// 총 단지수 & 각 단지내 집의 수 오름차순으로 정렬
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
			cin >> map[i];
	}

	vector<int> ans;
	int num = 0;	// 단지 수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '0' || visit[i][j])
				continue;
			num++;
			queue<pair<int, int>> q;
			visit[i][j] = 1;
			q.push({ i,j });
			int house = 0;	// 가구 수
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				house++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (map[nx][ny] == '0' || visit[nx][ny])
						continue;
					visit[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
			ans.push_back(house);
		}
	}

	cout << num << "\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}