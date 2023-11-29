//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/29.
//

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1001
typedef long long ll;
using namespace std;

ll n, m, ans;
priority_queue<ll, vector<ll>, greater<ll>> cards;

void input() {
    cin >> n >> m;
    
    ll num;
    for(ll i=0; i<n; i++) {
        cin >> num;
        cards.push(num);
    }
}

void find_min_score() {
    while(m--) {
        ll first = cards.top();
        cards.pop();
        ll second = cards.top();
        cards.pop();
        ll sum = first + second;
        cards.push(sum);
        cards.push(sum);
    }
}

void solve_ans() {
    while(!cards.empty()) {
        ans += cards.top();
        cards.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    find_min_score();
    solve_ans();
    cout << ans;
}
