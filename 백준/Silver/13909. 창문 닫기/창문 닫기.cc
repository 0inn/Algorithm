//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/12/02.
//

#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

ll n;

ll count_windows() {
    ll cnt = 1, cur = 1;
    
    while(true) {
        cur = (cnt * cnt);
        if(cur > n) break;
        cnt++;
    }
    
    return cnt-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cout << count_windows();
}
