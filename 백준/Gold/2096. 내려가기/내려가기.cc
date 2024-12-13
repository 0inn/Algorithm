//
//  내려가기.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 12/8/24.
//

#include <iostream>
#include <algorithm>
#include <limits.h>
typedef long long ll;
using namespace std;

struct Info {
    ll min, max;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    Info prev[3];
    for(int i=0; i<3; i++) {
        cin >> prev[i].min;
        prev[i].max = prev[i].min;
    }
    
    Info cur[3];
    for(int i=1; i<N; i++) {
        for(int j=0, num; j<3; j++) {
            cin >> num;
            
            ll prev_min = LLONG_MAX;
            ll prev_max = LLONG_MIN;
            for(int z=-1; z<=1; z++) {
                int nxt = j+z;
                if(nxt < 0 || nxt >= 3) continue;
                prev_min = min(prev_min, prev[nxt].min);
                prev_max = max(prev_max, prev[nxt].max);
            }
            
            cur[j].min = num + prev_min;
            cur[j].max = num + prev_max;
        }
        for(int j=0; j<3; j++) {
            prev[j].min = cur[j].min;
            prev[j].max = cur[j].max;
        }
    }
    
    ll ans_min = LLONG_MAX;
    ll ans_max = LLONG_MIN;
    for(int i=0; i<3; i++) {
        ans_min = min(ans_min, prev[i].min);
        ans_max = max(ans_max, prev[i].max);
    }
    
    cout << ans_max << " " << ans_min;
    
    return 0;
}
