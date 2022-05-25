#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N;
vector <int> t[MAX];
bool check[MAX];
int ans[MAX];

void dfs(int n) {
    check[n] = true;
    for (int i = 0; i < t[n].size(); i++) {
        int nxt_n = t[n][i];
        if (check[nxt_n]) continue;
        ans[nxt_n] = n;
        dfs(nxt_n);
    }
}

int main() {
    cin >> N;
    for (int i = 0, x, y; i < N - 1; i++) {
        cin >> x >> y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    dfs(1);
    
    for (int i = 2; i <= N; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}
