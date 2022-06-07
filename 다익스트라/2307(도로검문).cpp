#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

struct info {
	int n, w;
	info() {};
	info(int n, int w) : n(n), w(w) {};
	bool operator< (const info i) const {
		return w > i.w;
	}
};

int N, M;
vector<info> g[10001];
vector<int> path;
int route[10001];
int dist[10001];
int before, ans;
bool first = true;

void dijkstra(int n1, int n2) {
	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}
	priority_queue<info> pq;
	pq.push(info(1, 0));
	dist[1] = 0;
	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();
		for (int i = 0; i < g[cur.n].size(); i++) {
			int nxt_n = g[cur.n][i].n;
			int nxt_w = g[cur.n][i].w;

			if ((cur.n == n1 && nxt_n == n2) || (cur.n == n2 && nxt_n == n1)) continue;

			if (dist[nxt_n] > dist[cur.n] + nxt_w) {
				if (first) { route[nxt_n] = cur.n; }
				dist[nxt_n] = dist[cur.n] + nxt_w;
				pq.push(info(nxt_n, dist[nxt_n]));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0, a, b, t; i < M; i++) {
		cin >> a >> b >> t;
		g[a].push_back({ b,t });
		g[b].push_back({ a,t });
	}

	dijkstra(0, 0);
	before = dist[N];
	first = false;

	int tmp = N;
	while (tmp != 0) {
		path.push_back(tmp);
		tmp = route[tmp];
	}

	for (int i = path.size() - 1; i > 0; i--) {
		int n1 = path[i];
		int n2 = path[i - 1];
		dijkstra(n1, n2);	
		if (dist[N] == INF) {
			cout << -1;
			return 0;
		}
		ans = max(ans, dist[N] - before);
	}

	cout << ans;

	return 0;
}
