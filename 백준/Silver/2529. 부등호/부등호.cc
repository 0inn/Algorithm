//
//  부등호.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 9/22/24.
//

#include <iostream>
#include <string>
using namespace std;

int k;
long long max_ans=0;
long long min_ans=10e9;
string f_ans, s_ans;
string ops[10];
bool check[10];

bool checkOP(int l, string op, int r) {
    if(op == "<" && l < r) return true;
    else if(op == ">" && l > r) return true;
    return false;
}

void dfs(int n, int cnt, string num) {
    if(cnt == k) {
        if(max_ans < stoll(num)) {
            f_ans = num;
            max_ans = stoll(num);
        }
        if(min_ans > stoll(num)) {
            s_ans = num;
            min_ans = stoll(num);
        }
        return;
    }
    
    for(int i=0; i<=9; i++) {
        if(check[i]) continue;
        if(!checkOP(n, ops[cnt], i)) continue;
        check[i] = true;
        dfs(i, cnt+1, num+to_string(i));
        check[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k;
    for(int i=0; i<k; i++) {
        cin >> ops[i];
    }
    
    for(int i=0; i<=9; i++) {
        check[i] = true;
        dfs(i, 0, to_string(i));
        check[i] = false;
    }
    
    cout << f_ans << "\n" << s_ans;
}
