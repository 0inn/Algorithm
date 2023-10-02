#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;

vector<int> solution(vector<int> prices) {
    int len = prices.size()-1;
    
    for(int i=len; i>=0; i--) {
        if(i == prices.size()-1) {
            ans.push_back(0);
            continue;
        } else if(i == len-1) {
            ans.push_back(1);
            continue;
        }
        int cnt = 0;
        for(int j=i+1; j<len; j++) {
            if(prices[i] > prices[j]) {
                cnt = (j-i);
                break;
            }
        }
        cnt = (cnt == 0) ? len-i : cnt;
        ans.push_back(cnt);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}