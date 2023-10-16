//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/10/16.
//

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 200001
using namespace std;

struct Info {
    int s, t;
};

int N, ans=1;
Info arr[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(Info &a, Info &b) {
    return a.s < b.s;
}

void input() {
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> arr[i].s >> arr[i].t;
        pq.push(arr[i].t);
    }
    
    sort(arr, arr+N, cmp);
}

void cal_count() {
    for(int i=1; i<N; i++) {
        Info prev = arr[i-1];
        Info cur = arr[i];
        
        if(cur.s < prev.t) {
            if(!pq.empty() && pq.top() <= cur.s) {
                pq.pop();
            } else {
                ans++;
            }
        } else {
            pq.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    cal_count();
    cout << ans;
}
