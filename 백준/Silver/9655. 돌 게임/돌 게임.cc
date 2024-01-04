//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/12/06.
//

#include <iostream>
using namespace std;

int N;
string ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    ans = (N%2 == 0) ? "CY" : "SK";
    cout << ans;
}
