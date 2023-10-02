#include <vector>
#include <stack>

using namespace std;

stack<int> st;

vector<int> solution(vector<int> prices) {
    vector<int> ans(prices.size());
    int len = prices.size();
    
    for(int i=0; i<len; i++) {
        while(!st.empty() && prices[st.top()] > prices[i]) {
            ans[st.top()] = i-st.top();
            st.pop();
        }
        st.push(i);
    }
    
    while(!st.empty()) {
        ans[st.top()] = len-st.top()-1;
        st.pop();
    }
    
    return ans;
}