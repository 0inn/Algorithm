//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/12.
//

#include <iostream>
#include <queue>
#include <vector>
#define MAX 500001
typedef long long ll;

using namespace std;

struct Top {
    int idx, top;
};

struct Cmp {
    bool operator()(Top a, Top b) {
        return a.top > b.top;
    }
};

int N;
int arr[MAX], ans[MAX];

void input() {
    cin >> N;
    
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
}

void find_tops() {
    priority_queue<Top, vector<Top>, Cmp> pq;
    
    for(int i=N; i>=1; i--) {
        Top cur = Top{i, arr[i]};
        
        while(!pq.empty()) {
            Top ex = pq.top();
            
            if(cur.top > ex.top) {
                ans[ex.idx] = cur.idx;
                pq.pop();
            } else break;
        }
        
        pq.push(cur);
    }
    
    while(!pq.empty()) {
        Top ex = pq.top();
        ans[ex.idx] = 0;
        pq.pop();
    }
}

void output() {
    for(int i=1; i<=N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    find_tops();
    output();
}
