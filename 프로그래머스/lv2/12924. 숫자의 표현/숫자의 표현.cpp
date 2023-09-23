#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[10001], ans;

int solution(int n) {
    
    for(int i=1; i<=n; i++) {
        dp[i] = dp[i-1] + i;
    }
    
    int start = 0, end = 1;
    
    while(start < n) {
        int sum = dp[end] - dp[start];
        
        if(sum < n) {
            end++;
        } else if(sum >= n) {
            start++;
            if(sum == n) ans++;
        }
    }
    
    return ans;
}