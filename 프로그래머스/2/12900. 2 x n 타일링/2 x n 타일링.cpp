#include <string>
#include <vector>
#define MOD 1000000007;
using namespace std;

int dp[60001];

int solution(int n) {
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    
    return dp[n];
}