//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/09/04.
//

#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;

int T, N, ans;
int parent[MAX];
bool check[MAX];

void solution() {
    cin >> T;
    
    int u, v;
    while(T--) {
        cin >> N;
        // 각 노드 방문여부 초기화
        for(int i=1; i<N; i++) {
            parent[i] = i;
            check[i] = false;
        }
        // 간선 정보
        for(int i=0; i<N-1; i++) {
            cin >> u >> v;
            parent[v] = u;
        }
        cin >> u >> v;
        // 루트노드까지 거슬러 올라감
        check[u] = true;
        while(parent[u] != u) {
            u = parent[u];
            check[u] = true;
        }
        // 처음으로 겹칠 때나 루트노드일 때, 정답
        while(1) {
            if(check[v]) {
                ans = v;
                break;
            }
            v = parent[v];
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solution();
}
