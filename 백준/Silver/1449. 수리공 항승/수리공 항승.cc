//
//  수리공 항승.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 9/2/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> L;
    
    vector<int> pos;
    for(int i=0, p; i<N; i++) {
        cin >> p;
        pos.push_back(p);
    }
    sort(pos.begin(), pos.end());
    
    int s = pos[0];
    for(int i=1; i<N; i++){
        if(L <= pos[i]-s) {
            ans++;
            s = pos[i];
        }
    }
    
    cout << ans+1;
}
