//
//  한 줄로 서기.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 7/21/24.
//

#include <iostream>
#include <vector>

using namespace std;

int N, h[11];
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> h[i];
    }
    
    ans.push_back(N);
    for(int i=N-1; i>0; i--) {
        ans.insert(ans.begin()+h[i], i);
    }
    
    for(int i=0; i<N; i++) {
        cout << ans[i] << " ";
    }
}
