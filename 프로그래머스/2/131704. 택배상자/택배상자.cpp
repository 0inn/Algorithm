#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int ans = 0, idx = 0, cur = 1;
    stack<int> tmp;
    
    while(cur <= order.size()+1) {
        int item = order[idx];
        
        if(item == cur) {
            ans++;
            idx++;
            cur++;
        } else if (!tmp.empty() && item == tmp.top()) {
            ans++;
            idx++;
            tmp.pop();
        } else {
            tmp.push(cur);
            cur++;
        }
    }
    
    return ans;
}