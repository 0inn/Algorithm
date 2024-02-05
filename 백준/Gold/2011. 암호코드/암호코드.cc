//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2024/02/05.
//

#include <iostream>
#include <string>
#define MOD 1000000

using namespace std;
int dp[5001];
string pwd;

int find_cnt() {
    if(pwd[0] == '0') return 0;
    dp[0] = dp[1] = 1;
    for(int i=2; i<=pwd.size(); i++) {
        if(pwd[i-1] != '0') dp[i] = dp[i-1] % MOD;
        
        int tmp_pwd = (pwd[i-2]-'0') * 10 + (pwd[i-1]-'0');
        if(tmp_pwd >= 10 && tmp_pwd <= 26) dp[i] = (dp[i] + dp[i-2]) % MOD;
    }
    
    return dp[pwd.size()];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> pwd;
    cout << find_cnt();
}
