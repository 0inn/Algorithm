//
//  창고 다각형.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 7/10/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N, toph, topx, ans, en;
int col[1001];

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0,x,y;i<N; i++) {
        cin >> x >> y;
        col[x] = y;
        if(toph < y) {
            toph = y;
            topx = x;
        }
        en = max(en, x);
    }
    
    // search from left
    int lh = 0;
    for(int i=1; i<topx; i++) {
        lh = max(lh, col[i]);
        ans += lh;
    }
    
    // search from right
    int rh = 0;
    for(int i=en; i>topx; i--) {
        rh = max(rh, col[i]);
        ans += rh;
    }
    
    cout << ans + toph;
}
