//
//  14490(백대열).cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/04/29.
//

#include <bits/stdc++.h>
using namespace std;

int n, m;
char c;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    cin >> n >> c >> m;
    int num = gcd(n, m);
    cout << n / num<< ":" << m / num;
}
