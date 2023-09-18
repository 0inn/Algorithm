//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/09/18.
//

#include <iostream>
#include <string>
#include <algorithm>
#define MIN -987654321
typedef long long ll;

using namespace std;

ll N, ans = MIN;
string EXP;

void input() {
    cin >> N >> EXP;
}

ll calculate(ll x, char op, ll y) {
    if(op == '+') {
        return x+y;
    } else if(op == '-') {
        return x-y;
    } else {
        return x*y;
    }
}

void search_exp(ll idx, ll result) {
    if(idx >= N-2) {
        ans = max(ans, result);
        return;
    }
    ll nxt_result = calculate(result, EXP[idx+1], EXP[idx+2]-'0');
    search_exp(idx+2, nxt_result);
    
    if(idx >= N-4) {
        return;
    }
    nxt_result = calculate(EXP[idx+2]-'0', EXP[idx+3], EXP[idx+4]-'0');
    search_exp(idx+4, calculate(result, EXP[idx+1], nxt_result));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    input();
    search_exp(0, EXP[0]-'0');
    cout << ans;
}
