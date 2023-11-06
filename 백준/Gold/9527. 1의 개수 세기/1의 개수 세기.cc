//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/06.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll A, B, ans;
ll d[55];

void input() {
    cin >> A >> B;
}

void set_sum() {
    d[0] = 1;
    for(ll i=1; i<55; i++) {
        d[i] = 2 * d[i-1] + (1LL << i);
    }
}

ll go(ll x) {
    ans = x & 1;
    
    for(ll i=54; i>0; i--) {
        if(x & (1LL << i)) { // i번째 비트가 켜져있다면
            ans += d[i-1] + (x - (1LL << i) + 1); // 전의 모든 1의 개수의 합 + 더해줘야 하는 i번 비트의 개수
            x -= 1LL << i; // 비트 옮기기
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    set_sum();
    cout << go(B) - go(A-1);
}

