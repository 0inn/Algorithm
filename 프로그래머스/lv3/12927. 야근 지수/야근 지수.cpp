#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
typedef long long ll;

using namespace std;

ll ans;

ll solution(int n, vector<int> works) {
    sort(works.begin(), works.end(), greater<int>());
    
    if(works.size() == 1) {
        ans = works[0] - n;
        return ans <= 0 ? 0 : pow(ans, 2);
    }
    
    while(n > 0) {
        for(int i=0; i<works.size(); i++) {
            if(i == 0) {
                while(works[i] >= works[i+1] && n > 0) {
                    works[i]--;
                    n--;
                }
            } else {
                while(works[i] > works[i-1] && n > 0) {
                    works[i]--;
                    n--;
                }
            }
        }
    }
    
    for(int i=0; i<works.size(); i++) {
        if(works[i] < 0) continue;
        ans += pow(works[i], 2);
    }
    
    return ans;
}