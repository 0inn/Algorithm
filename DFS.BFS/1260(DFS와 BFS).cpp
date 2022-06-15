#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, V;
vector<int> g[1001];
bool check[1001];

void dfs(int n) {
    check[n] = true;
    cout << n << " ";
    for (int i = 0; i < g[n].size(); i++) {
        if (!check[g[n][i]]) {
            dfs(g[n][i]);
        }
    }
}

void bfs(int n) {
    check[n] = true;
    queue<int> q;
    q.push(n);
    
    while(!q.empty()) {
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for (int i = 0; i < g[cur].size(); i++) {
            if (!check[g[cur][i]]) {
                q.push(g[cur][i]);
                check[g[cur][i]] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> V;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        sort(g[u].begin(), g[u].end());
        sort(g[v].begin(), g[v].end());
    }
    
    dfs(V);
    cout << "\n";
    memset(check, false, sizeof(check));
    bfs(V);
}
