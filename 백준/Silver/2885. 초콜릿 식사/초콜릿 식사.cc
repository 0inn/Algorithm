//
//  초콜릿 식사.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 12/8/24.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int K;
    cin >> K;

    int total = 1;
    
    while(total < K) {
        total *= 2;
    }
    
    int num = total;
    int ans = 0;
    while(true) {
        K %= num;
        if(K == 0) break;
        num/=2;
        ans++;
    }
    
    cout << total << " " << ans;
    
    return 0;
}
