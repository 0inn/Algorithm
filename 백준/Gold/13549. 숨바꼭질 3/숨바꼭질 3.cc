//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/17.
//

#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int N, K;
bool visited[MAX];

void input() {
    cin >> N >> K;
}

int find_min_time() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, N});
    visited[N] = true;
    
    while(!pq.empty()) {
        int time = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        
        if(x == K) return time;
        
        if(x * 2 < MAX && !visited[x * 2]) {
            pq.push({time, x * 2});
            visited[x * 2] = true;
        }
        
        if(x + 1 < MAX && !visited[x + 1]) {
            pq.push({time + 1, x + 1});
            visited[x + 1] = true;
        }
        
        if(x >= 1 && !visited[x - 1]) {
            pq.push({time + 1, x - 1});
            visited[x - 1] = true;
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    cout << find_min_time();
}
