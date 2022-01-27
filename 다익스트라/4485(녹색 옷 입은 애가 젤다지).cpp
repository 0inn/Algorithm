#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

struct info {
	int i, j, w;
	info() {};
	info(int i, int j, int w) :i(i), j(j), w(w) {};

	bool operator <(const info i) const {
		return w > i.w;
	}
};

int N, w, t, f;
bool check[130][130];
vector<info> g[130][130];
int dist[130][130];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (true) {
		cin >> N;
		if (N == 0) break;
		t++;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				check[i][j] = false;
				dist[i][j] = INF;
				g[i][j].clear();
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> w;
				if (i == 1 && j == 1) { f = w; continue; }
				// 나에게 들어오는 화살표
				g[i][j - 1].push_back(info(i, j, w));
				g[i - 1][j].push_back(info(i, j, w));
				g[i][j + 1].push_back(info(i, j, w));
				g[i + 1][j].push_back(info(i, j, w));
			}
		}

		// 다익스트라
		priority_queue<info> pq;
		pq.push(info(1, 1, 0));
		dist[1][1] = 0;
		while (!pq.empty()) {
			info cur = pq.top();
			pq.pop();
			if (check[cur.i][cur.j]) continue;
			check[cur.i][cur.j] = true;
			for (int z = 0; z < g[cur.i][cur.j].size(); z++) {
				int nxt_i = g[cur.i][cur.j][z].i;
				int nxt_j = g[cur.i][cur.j][z].j;
				int nxt_w = g[cur.i][cur.j][z].w;
				if (dist[cur.i][cur.j] + nxt_w < dist[nxt_i][nxt_j]) {
					dist[nxt_i][nxt_j] = dist[cur.i][cur.j] + nxt_w;
					pq.push(info(nxt_i, nxt_j, dist[nxt_i][nxt_j]));
				}
			}
		}

		cout << "Problem " << t << ": " << dist[N][N] + f << "\n";

	}
	return 0;
}