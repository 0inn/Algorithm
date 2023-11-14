//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/15.
//

#include <iostream>

using namespace std;

int T;

int calculate_count(int n) {
    int ans = 1 + (n / 2) + (n / 3);
    
    for(int i=2; i<n; i+=3) {
        ans += (n - i - 1) / 2;
    }
    
    return ans;
}

void solution() {
    cin >> T;
    
    int n;
    while(T--) {
        cin >> n;
        cout << calculate_count(n) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solution();
}
