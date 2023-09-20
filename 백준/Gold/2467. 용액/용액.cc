//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/09/20.
//

#include <iostream>
#include <cmath>
#define MAX 100001
#define MAXV 1000000000
typedef long long ll;

using namespace std;

struct Solution {
    ll x, y;
};

ll N;
ll arr[MAX];
Solution ans = Solution{MAXV, MAXV};

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
}

void calculate() {
    ll sum = 0;
    ll start = 0, end = N-1;
    
    while(start != end) {
        ll x = arr[start], y = arr[end];
        sum = x + y;
        if (abs(sum) < abs(ans.x + ans.y)) {
            ans.x = x;
            ans.y = y;
        }
        
        if(sum < 0) {
            start++;
        } else {
            end--;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    calculate();
    cout << ans.x << " " << ans.y;
}
