//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/10/04.
//

#include <iostream>
#include <algorithm>
#define MAX 1500001

using namespace std;

struct Schedule {
    int T, P;
};

int N, ans;
Schedule arr[MAX];
int dp[MAX];

void calculate_benefit() {
    int cur_max = 0;
    for(int i=0; i<N; i++) {
        cur_max = max(cur_max, dp[i]);
        int nxt_idx = i + arr[i].T;
        int nxt_value = arr[i].P + cur_max;
        
        dp[nxt_idx] = max(dp[nxt_idx], nxt_value);
        if(nxt_idx <= N) {
            ans = max(ans, dp[nxt_idx]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i].T >> arr[i].P;
    }
    
    calculate_benefit();
    cout << ans;
}
