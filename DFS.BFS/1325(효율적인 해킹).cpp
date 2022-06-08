#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
    int cnt, i;
};

int N, M, cnt, ans, maxAns;
vector<int> g[10001];
vector<info> answer;
bool check[10001];

void dfs(int n) {
    check[n] = true;
    cnt++;
    for (int i = 0; i < g[n].size(); i++) {
        int nxt = g[n][i];
        if(!check[nxt]) {
            dfs(nxt);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        g[v].push_back(u);  // v를 해킹하면, u도 해킹 가능 (v -> u)
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) { check[j] = false; }
        cnt = 0;
        dfs(i);
        answer.push_back({cnt, i});
        maxAns = max(maxAns, cnt);
    }
    
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i].cnt == maxAns) { cout << answer[i].i << " "; }
    }
    
    return 0;
}
