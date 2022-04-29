//
//  2606(바이러스).cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/04/29.
//

#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N,E;
int ans;

bool check[MAX];
vector<int> com[MAX];

void bfs(int start) {
    check[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans++;
        for (int i = 0; i < com[cur].size(); i++) {
            int nxt = com[cur][i];
            if (!check[nxt]) {
                q.push(nxt);
            }
            check[nxt] = true;
        }
    }
}

int main() {
    cin >> N >> E;
    for (int i = 0, x, y; i < E; i++) {
        cin >> x >> y;
        com[x].push_back(y);
        com[y].push_back(x);
    }
    
    bfs(1);
    cout << ans - 1;
}
