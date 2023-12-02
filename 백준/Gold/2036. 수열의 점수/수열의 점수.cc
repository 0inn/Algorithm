//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/29.
//

#include <iostream>
#include <queue>
#define MAX 100001
typedef long long ll;
using namespace std;

ll n, zero_cnt, ans;
ll minus_len, minus_num;
priority_queue<ll, vector<ll>, greater<ll>> minus_nums;
priority_queue<ll, vector<ll>> plus_nums;

void input() {
    cin >> n;
    
    ll num;
    while(n--) {
        cin >> num;
        if(num < 0) minus_nums.push(num);
        else plus_nums.push(num);
    }
    
    minus_len = minus_nums.size();
}

ll get_num(bool is_minus) {
    ll num = 0;
    
    if(is_minus && !minus_nums.empty()) {
        num = minus_nums.top();
        if(minus_len % 2 == 1 && minus_nums.size() == 1) minus_num = num;
        minus_nums.pop();
    } else if(!is_minus && !plus_nums.empty()) {
        num = plus_nums.top();
        if(num == 0) zero_cnt++;
        plus_nums.pop();
    }
    
    return num;
}

void start_nums() {
    while(!minus_nums.empty()) {
        ll first = get_num(true);
        ll second = get_num(true);
        if(first == 0 || second == 0) {
            ans += (first + second);
        } else {
            ans += (first * second);
        }
    }
    
    while(!plus_nums.empty()) {
        ll first = get_num(false);
        ll second = get_num(false);
        if(first == 0 || first == 1 || second == 0 || second == 1) {
            ans += (first + second);
        } else {
            ans += (first * second);
        }
    }
    
    if(minus_num != 0 && zero_cnt > 0) {
        ans -= minus_num;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    start_nums();
    cout << ans;
}
