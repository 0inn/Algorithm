//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/08.
//

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

ll cal_max(vector<ll> stock) {
    ll max_value = -1, ans = 0;
    
    for(int i=stock.size()-1; i>=0; i--) {
        ll cur = stock[i];
        if(cur < max_value) ans += (max_value - cur);
        max_value = max(max_value, cur);
    }
    
    return ans;
}

void solution() {
    int T;
    cin >> T;
    
    ll N;
    while(T--) {
        cin >> N;
        
        int num;
        vector<ll> stock;
        while(N--) {
            cin >> num;
            stock.push_back(num);
        }
        
        cout << cal_max(stock) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solution();
}
