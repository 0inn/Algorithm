//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/09/22.
//

#include <iostream>
#define MAX 1000001

using namespace std;

int N, ans;
int dp[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0, n; i<N; i++) {
        cin >> n;
        dp[n] = dp[n-1] + 1;
        ans = max(ans, dp[n]);
    }
    
    cout << N - ans;
}
