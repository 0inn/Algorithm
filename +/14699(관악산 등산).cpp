// DFS + 동적계획법(DP)

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 5001
using namespace std;

int N, M;
int height[MAX], dp[MAX];;
vector<int> g[MAX];

int dfs(int n) {
    if (dp[n] != 0) { return dp[n]; }
    for (int i = 0; i < g[n].size(); i++) {
        dp[n] = max(dp[n], dfs(g[n][i]));
    }
    return ++dp[n];
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> height[i];
    }
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        if (height[u] < height[v]) {
            g[u].push_back(v);
        } else {
            g[v].push_back(u);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << dfs(i) << "\n";
    }
    
    return 0;
}
