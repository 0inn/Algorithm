//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/09/13.
//

#include <iostream>
typedef long long ll;

using namespace std;

ll N, B;
ll a[5][5], ans[5][5], tmp[5][5];

void input() {
    cin >> N >> B;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> a[i][j];
        }
        ans[i][i] = 1;
    }
}

void multiply(ll v1[5][5], ll v2[5][5]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tmp[i][j] = 0;
            for(int k=0; k<N; k++) {
                tmp[i][j] += v1[i][k] * v2[k][j];
            }
            tmp[i][j] %= 1000;
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            v1[i][j] = tmp[i][j];
        }
    }
}

void output() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    
    while(B) {
        if(B % 2 == 1) { // 홀수면, 정답에 A행렬 곱하기
            multiply(ans, a);
        }
        multiply(a, a); // 짝수면, A 제곱하기
        B /= 2;
    }
    
    output();
}
