#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int s = 0, e = 0;
    int sum = sequence[0];
    int subLen = sequence.size() + 1;
    pair<int, int> result;
    
    while (s <= e && e < sequence.size()) {
        if (sum < k) sum += sequence[++e];
        else if (sum == k) {
            if (e-s+1 < subLen) {
                subLen = e-s+1;
                result = {s, e};
            } else if (e-s+1 == subLen) {
                if (s < result.first) {
                    result = {s, e};
                }
            }
            
            sum -= sequence[s++];
        } 
        else sum -= sequence[s++];
    }
    
    return {result.first, result.second};
}