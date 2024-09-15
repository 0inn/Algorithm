//
//  배열 복원하기.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 9/15/24.
//

#include <iostream>
using namespace std;

int H, W, X, Y;
int arr[601][601];

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    
    cin >> H >> W >> X >> Y;
    
    for(int i=0; i<H+X; i++) {
        for(int j=0; j<W+Y; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(i-X>=0 && j-Y>=0) arr[i][j] -= arr[i-X][j-Y];
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
