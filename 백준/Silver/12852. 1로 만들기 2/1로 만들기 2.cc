//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/10.
//

#include <iostream>
#define MAX 1000001

using namespace std;

int n;
int dp[MAX] = {0, };
int pre[MAX] = {0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + 1;
        pre[i] = i-1;
        if(i%3 == 0 && dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] + 1;
            pre[i] = i/3;
        }
        if(i%2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            pre[i] = i/2;
        }
    }
    
    cout << dp[n] << "\n";
    
    int cur = n;
    while(true) {
        cout << cur << " ";
        if(cur == 1) break;
        cur = pre[cur];
    }
}
