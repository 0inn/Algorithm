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
        dp[i] = A[i];
        for (int j = i; j >= 0; j--) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], A[i] + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
    
    return 0;
}
