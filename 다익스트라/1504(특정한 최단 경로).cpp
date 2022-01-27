#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

struct info {
	int n, w;
	info() {};
	info(int n, int w) :n(n), w(w) {};

	bool operator<(const info i)const {
		return w > i.w;
	}
};

int N, E, n1, n2;
vector<info> g[810];
int dist[810];
bool check[810];

int dijkstra(int start, int end) {
	for (int i = 0; i <= N; i++) { // memset은 0이나 -1로 초기화할 때 사용
		dist[i] = INF;
		check[i] = false;
	}
	priority_queue<info> pq;
	pq.push(info(start, 0));
	dist[start] = 0;
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
	if (dist[end] == INF) return -1;
	else return dist[end];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> E;
	for (int i = 0, u, v, w; i < E; i++) {
		cin >> u >> v >> w;
		g[u].push_back(info(v, w));
		g[v].push_back(info(u, w));
	}
	cin >> n1 >> n2;
	// 1->n1->n2->N
	// 1->n2->n1->N
	int path11 = dijkstra(1, n1);
	int path12 = dijkstra(n1, n2);
	int path13 = dijkstra(n2, N);
	int path21 = dijkstra(1, n2);
	int path22 = path12;
	int path23 = dijkstra(n1, N);

	// INF를 3번 더해줘서 계속 오류 -> 더하기 전에 미리 오류처리
	if (path11 == -1 || path12 == -1 || path13 == -1 || path21 == -1 || path23 == -1) {
		cout << -1;
	}
	else {
		cout << min(path11 + path12 + path13, path21 + path22 + path23);
	}

	return 0;
}