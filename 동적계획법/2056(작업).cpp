//
//  2056(작업).cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/03/06.
//

#include <bits/stdc++.h>
using namespace std;

int N;
int arr[10001];
int dp[10001];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i = 1, job, cnt; i <= N; i++) {
        cin >> job >> cnt;
        arr[i] = job;
        dp[i] = job;
        for(int j = 0, prior; j < cnt; j++) {
            cin >> prior;
            dp[i] = max(dp[prior] + arr[i], dp[i]);
        }
        ans = max(ans, dp[i]);  // 무조건 맨 끝 번호가 늦게 끝나는 것이 아니므로
    }
    
    cout << ans << "\n";
    
    return 0;
}
