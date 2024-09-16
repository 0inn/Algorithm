#include<bits/stdc++.h>
using namespace std;

int n, p1, p2, m;
vector<int> v[101];
int depth[101];

void dfs(int start, int d) {
	for (int i = 0; i < v[start].size(); i++) {
		int nxt = v[start][i];
		if (depth[nxt] == 0) {
			depth[nxt] = d + 1;
			dfs(nxt, depth[nxt]);
		}
	}
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
	dfs(p1, 0);
	if (depth[p2] == 0) cout << -1;
	else cout << depth[p2];

	return 0;
}