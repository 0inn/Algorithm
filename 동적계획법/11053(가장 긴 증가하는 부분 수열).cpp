#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int A[1001], dp[1001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j <= i; j++) {
            if (A[j] < A[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
}
