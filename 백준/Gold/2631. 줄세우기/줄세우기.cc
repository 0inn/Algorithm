//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/08/27.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int nums[201];
int dp[201];

void input() {
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }
}

void solution() {
    dp[0] = 1;
    
    for(int i=1; i<N; i++) {
        int maxValue = 0;
        for(int j=0; j<i; j++) {
            if(nums[j] < nums[i] && maxValue < dp[j]) {
                maxValue = dp[j];
            }
        }
        dp[i] = maxValue + 1;
        ans = max(ans, dp[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solution();
    cout << N - ans;
}
