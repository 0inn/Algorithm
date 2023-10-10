#include<bits/stdc++.h>
#define MAX 1001
#define INF 99987654321
using namespace std;

struct info {
	int n, w;
	info() {};
	info(int n, int w) :n(n), w(w) {};
	bool operator <(const info i) const {
		return w > i.w;
	}
};

int N, M, S, D;
vector<info> g[MAX];
int dist[MAX];
int route[MAX];
bool check[MAX];

int main() {	// 최소 비용 + 최소 개수 + 경로 출력
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i <= N; i++) dist[i] = INF;
	for (int i = 0, u, v, w; i < M; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
	}
	cin >> S >> D;

	priority_queue<info> pq;
	pq.push({ S,0 });
	dist[S] = 0;
	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();
		if (check[cur.n]) continue;
		check[cur.n] = true;
		for (int i = 0; i < g[cur.n].size(); i++) {
			int nxt_n = g[cur.n][i].n;
			int nxt_w = g[cur.n][i].w;
			if (dist[nxt_n] > dist[cur.n] + nxt_w) {
				route[nxt_n] = cur.n;
				dist[nxt_n] = dist[cur.n] + nxt_w;
				pq.push({ nxt_n,dist[nxt_n] });
			}
		}
	}
	cout << dist[D] << "\n";

	vector<int> ans;
	while (D != 0) {
		ans.push_back(D);
		D = route[D];
	}
	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}