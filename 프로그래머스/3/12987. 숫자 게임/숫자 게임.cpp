#include <vector>
#include <algorithm>

using namespace std;

int ans;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int idx = 0;
    for(auto a: A) {
        while(idx < B.size()) {
            if(a < B[idx]) {
                ans++;
                idx++;
                break;
            }
            idx++;
        }
    }
    
    return ans;
}