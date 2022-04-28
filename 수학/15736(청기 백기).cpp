//
//  15736(청기 백기).cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/04/29.
//

#include <bits/stdc++.h>
#define MAX 2100000001
using namespace std;

int N;

bool isSquare(int num) {
    int temp = sqrt(num);
    return temp * temp == num;
}

int main() {
    
    cin >> N;

    while(true) {
        if (isSquare(N)) {
            cout << sqrt(N);
            break;
        }
        N--;
    }
    
}
