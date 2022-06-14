#include <iostream>
#define MOD 1000000000
typedef long long ll;
using namespace std;

int N, K;
ll dp[201][201];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    
    for (int i = 0; i <= N; i++) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }
    
    cout << dp[K][N];
}
