//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/06/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 50001
#define INF 1e9

using namespace std;

struct Node {
    int n, w;
};

int N, M;
vector<Node> arr[MAX];
int dist[MAX];

// 최소 여물 계산
int cal_min_hay() {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    dist[1] = 0;
    
    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        
        for(int i=0; i<arr[cur].size(); i++) {
            int nxt_n = arr[cur][i].n;
            int nxt_w = arr[cur][i].w;
            int nxt_dist = dist[cur] + nxt_w;
            
            if(nxt_dist < dist[nxt_n]) {
                dist[nxt_n] = nxt_dist;
                pq.push(nxt_n);
            }
        }
    }
    
    return dist[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> N >> M;
    
    int u, v, w;
    for(int i=0; i<M; i++) {
        cin >> u >> v >> w;
        arr[u].push_back(Node{v, w});
        arr[v].push_back(Node{u, w});
    }
    
    fill(dist, dist+MAX, INF);
    
    cout << cal_min_hay();
}
