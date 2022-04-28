//
//  1904(01타일).cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/04/28.
//

#include <bits/stdc++.h>
#define MAX 1000001
#define MOD 15746
using namespace std;

int N;
int dp[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    dp[1] = 1;
    dp[2] = 2;
    
    cin >> N;
    
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    
    cout << dp[N];
}
