//
//  1309(동물원).cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/03/05.
//

#include <bits/stdc++.h>
#define MOD 9901
using namespace std;

int N;
int dp[2][100001];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    dp[0][1] = 1;
    dp[1][1] = 1;
    
    for (int i = 2; i <= N; i++) {
        dp[0][i] = (dp[0][i-1] + dp[1][i-1] * 2) % MOD;
        dp[1][i] = (dp[0][i-1] + dp[1][i-1]) % MOD;
    }
    
    ans = (dp[0][N] + dp[1][N] * 2) % MOD;
    cout << ans << "\n";
    
    return 0;
}
