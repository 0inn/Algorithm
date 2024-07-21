//
//  근손실.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 7/21/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
    int idx, k;
};

int N, K, ans;
vector<Info> v;

bool compare(const Info i1, const Info i2){
    return i1.idx < i2.idx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    for(int i=0,m; i<N; i++) {
        cin >> m;
        v.push_back(Info{i, m-K});
    }
    
    do {
        if(v[0].k < 0) continue;
        
        int cur = 0;
        for(int i=0; i<N; i++) {
            cur += v[i].k;
            if(cur < 0) break;
        }
        if(cur >= 0) ans++;
    } while(next_permutation(v.begin(), v.end(), compare));
    
    cout << ans;
}
