//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/05/27.
//

#include <iostream>
#include <algorithm>

using namespace std;

int H, W, ans;
int arr[501];

// 빗물 계산하기
void calRain() {
    for(int i=1; i<W-1; i++) {
        int left = 0, right = 0;
        
        for(int l=0; l<i; l++) left = max(left, arr[l]);
        for(int r=W-1; r>i; r--) right = max(right, arr[r]);
        
        ans += max(0, min(left, right) - arr[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> H >> W;
    for(int i=0; i<W; i++) {
        cin >> arr[i];
    }
    
    calRain();
    
    cout << ans;
}
