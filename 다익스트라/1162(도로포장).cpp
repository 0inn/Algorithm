#include<bits/stdc++.h>
#define INF 9223372036854775800
using namespace std;
typedef long long ll;

struct info {
	ll n, w, k;
	info() {};
	info(ll n, ll w, ll k) :n(n), w(w), k(k) {};
	bool operator < (const info i) const {
		return w > i.w;
	}
};

int N, M, K;
vector<info> g[10001];
ll dist[10001][21];
bool check[10001][21];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 0, u, v, w; i < M; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w,0 });
		g[v].push_back({ u,w,0 });
	}

	priority_queue<info> pq;
	pq.push({ 1,0,0 });
	dist[1][0] = 0;
	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();
		ll cnt = cur.k;
		if (check[cur.n][cur.k]) continue;
		check[cur.n][cur.k] = true;
		for (int i = 0; i < g[cur.n].size(); i++) {
			ll nxt_n = g[cur.n][i].n;
			ll nxt_w = g[cur.n][i].w;
			if (dist[nxt_n][cnt] > dist[cur.n][cnt] + nxt_w) {
				dist[nxt_n][cnt] = dist[cur.n][cnt] + nxt_w;
				pq.push({ nxt_n,dist[nxt_n][cnt],cnt });
			}
			if (dist[nxt_n][cnt + 1] > dist[cur.n][cnt] && (cnt + 1) <= K) {
				dist[nxt_n][cnt + 1] = dist[cur.n][cnt];
				pq.push({ nxt_n,dist[nxt_n][cnt + 1],cnt + 1 });
			}
		}
	}
	ll ans = INF;
	for (int i = 0; i <= K; i++) {
		ans = min(ans, dist[N][i]);
	}
	cout << ans;

	return 0;
}
