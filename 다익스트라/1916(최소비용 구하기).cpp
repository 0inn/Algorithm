#include<bits/stdc++.h>
#define MAX 1001
#define INF 987654321
using namespace std;

struct info {
	int n, w;
	info() {};
	info(int n, int w) :n(n), w(w) {};

	bool operator<(const info i) const {
		return w > i.w;
	}
};

int n, m, s, e;
vector<info> g[MAX];
bool check[MAX];
int dist[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back(info(v, w));
	}

	cin >> s >> e;
	priority_queue<info> pq;
	pq.push(info(s, 0));
	dist[s] = 0;
	while (!pq.empty()) {	// dijkstra
		info cur = pq.top();
		pq.pop();
		if (check[cur.n]) continue;
		check[cur.n] = true;
		for (int i = 0; i < g[cur.n].size(); i++) {
			int nxt_n = g[cur.n][i].n;
			int nxt_w = g[cur.n][i].w;
			if (dist[nxt_n] > nxt_w + dist[cur.n]) {
				dist[nxt_n] = nxt_w + dist[cur.n];
				pq.push(info(nxt_n, dist[nxt_n]));
			}
		}
	}

	cout << dist[e];

	return 0;
}
