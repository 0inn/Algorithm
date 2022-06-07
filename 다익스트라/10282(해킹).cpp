#include<bits/stdc++.h>
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

int t, n, d, c;
vector<info> g[10001];
int dist[10001];
bool check[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> d >> c;
		for (int i = 0; i <= n; i++) {
			dist[i] = INF;
			check[i] = false;
			g[i].clear();
		}
		for (int i = 0, a, b, s; i < d; i++) {
			cin >> a >> b >> s;	
			g[b].push_back(info(a, s));
		}

		priority_queue<info> pq;
		pq.push(info(c, 0));
		dist[c] = 0;
		while (!pq.empty()) {
			info cur = pq.top();
			pq.pop();
			if (check[cur.n]) continue;
			check[cur.n] = true;
			for (int i = 0; i < g[cur.n].size(); i++) {
				int nxt_n = g[cur.n][i].n;
				int nxt_w = g[cur.n][i].w;
				if (dist[nxt_n] > dist[cur.n] + nxt_w) {
					dist[nxt_n] = dist[cur.n] + nxt_w;
					pq.push(info(nxt_n, dist[nxt_n]));
				}
			}
		}

		int cnt = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] == INF) continue;
			if (dist[i] != INF) cnt++;
			if (ans < dist[i]) ans = dist[i];
		}
		cout << cnt << " " << ans << "\n";
	}

	return 0;
}
