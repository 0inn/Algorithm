//
//  하노이 탑 이동 순서.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 7/21/24.
//

#include <iostream>
#include <cmath>

using namespace std;

int N, ans;

void hanoi(int n, int from, int by, int to) {
    if(n==1) cout << from << " " << to << "\n";
    else {
        hanoi(n-1, from, to, by);
        cout << from << " " << to << "\n";
        hanoi(n-1, by, from, to);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    ans = pow(2, N)-1;
    cout << ans << "\n";
    hanoi(N, 1, 2, 3);
}
