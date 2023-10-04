//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/09/30.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#define MAX 101

using namespace std;

struct Info {
    int x, p;
};

int N, total, ans;
Info group[MAX] = {};
vector<int> graph[MAX] = {};

bool check_if_connect(vector<int> group) {
    if(group.empty()) return false;
    
    bool connect_check[MAX] = {};
    int cnt = 1;
    queue<int> q;
    q.push(group[0]);
    connect_check[group[0]] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            if(connect_check[nxt]) continue;
            if(find(group.begin(), group.end(), nxt) != group.end()) {
                cnt++;
                q.push(nxt);
                connect_check[nxt] = true;
            }
        }
    }
    
    return cnt == group.size();
}

void select(int r) {
    vector<int> one;
    vector<int> two;
    
    vector<bool> v(N, true);
    for(int i=1; i<=N-r; i++) {
        v[i] = false;
        
        do {
            int sum = 0;
            for(int k=1; k<=N; k++) {
                if(v[k]) {
                    one.push_back(group[k].x);
                    sum += group[k].p;
                } else {
                    two.push_back(group[k].x);
                }
            }
            if(check_if_connect(one) && check_if_connect(two)) {
                ans = min(ans, abs(total - (2 * sum)));
            }
            one.clear();
            two.clear();
        } while(next_permutation(v.begin(), v.end()));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1, num; i <= N; i++) {
        group[i].x = i;
        cin >> num;
        group[i].p = num;
        total += num;
    }
    ans = total;

    for (int u = 1, cnt, v; u <= N; u++) {
        cin >> cnt;
        while (cnt--) {
            cin >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    for(int i=1; i<=N; i++) {
        select(i);
    }

    if (ans == total) ans = -1;
    cout << ans;
}
