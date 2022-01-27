#include<bits/stdc++.h>
using namespace std;

int n, p1, p2, m;
vector<int> v[101];
int depth[101];

int bfs(int start, int end) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		if (cur == end) return depth[cur];
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i];
			if (depth[nxt] == 0) {
				q.push(nxt);
				depth[nxt] = depth[cur] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> p1 >> p2 >> m;
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;	// x가 y의 부모
		v[x].push_back(y);
		v[y].push_back(x);
	}

	cout << bfs(p1, p2);

	return 0;
}