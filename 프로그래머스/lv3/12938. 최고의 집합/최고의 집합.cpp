#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;

vector<int> solution(int n, int s) {
    int num = s / n;
    int rest = s % n;
    
    if(num == 0) {
        ans.push_back(-1);
        return ans;
    }
    
    for(int i=0; i<n; i++) {
        ans.push_back(num);
    }
    
    int len = n-1;
    for(int i=len; i>len-rest; i--) {
        ans[i]++;
    }
    sort(ans.begin(), ans.end());
    
    return ans;
}