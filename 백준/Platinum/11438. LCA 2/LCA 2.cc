//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/05/09.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 100001

using namespace std;

int n, m;
vector<int> adj[MAX];
int parent[MAX][18], level[MAX];
int max_level;

int lca(int a, int b) {
    if(a == 1 || b == 1) return 1;

    // a와 b중 level이 더 높은 노드에 대해 2^k번째 조상 노드를 찾아 올라간다.
    if(level[a] < level[b]) swap(a, b);

    // 두 노드의 level이 같아지도록 조정
    if(level[a] != level[b]) {
        for(int i=max_level; i>=0; i--) {
            if(level[parent[a][i]] >= level[b]) {
                a = parent[a][i];
            }
        }
    }

    // 동일 level로 맞췄으므로 공통 조상 찾기
    int result = a;
    if (a != b) {
        for(int i=max_level; i>=0; i--) {
            if(parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
            result = parent[a][i];
        }
    }

    return result;
}

void set_tree(int n, int p, int lv) {
    level[n] = lv;
    parent[n][0] = p;
    
    //parent[i][j] : i번 노드의 2^j번째 조상
    for(int i=1; i<=max_level; i++) {
        parent[n][i] = parent[parent[n][i-1]][i-1];
    }
    
    for(int i=0; i<adj[n].size(); i++) {
        int child = adj[n][i];
        if(child == p) continue;
        
        set_tree(child, n, lv+1);
    }
}

void init() {
    int x, y;
    cin >> n;
    
    for(int i=0; i<n-1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    
    init();
    max_level = (int)floor(log2(MAX));
    set_tree(1, 0, 1);
    
    int x, y;
    cin >> m;
    
    for(int i=0; i<m; i++) {
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
}
