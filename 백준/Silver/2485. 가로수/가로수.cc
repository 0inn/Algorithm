//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/12/02.
//

#include <iostream>
#include <algorithm>
#define MAX 100001
typedef long long ll;
using namespace std;

ll n, trees[MAX];

void input() {
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> trees[i];
    }
}

ll gcd(ll max, ll min){
    while(min != 0){
        ll remain = max % min;
        max = min;
        min = remain;
    }
    
    return max;
}

ll find_dist() {
    ll dist = abs(trees[0] - trees[1]);
    
    for(int i=2; i<n; i++) {
        ll diff = abs(trees[i-1] - trees[i]);
        dist = gcd(dist, diff);
    }
    
    return dist;
}

ll count_trees(ll dist) {
    ll cnt = 0;
    
    for(int i=1; i<n; i++) {
        ll diff = abs(trees[i-1] - trees[i]);
        cnt += (diff / dist) - 1;
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    ll dist = find_dist();
    cout << count_trees(dist);
}
