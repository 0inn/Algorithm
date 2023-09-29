#include <vector>
#include <iostream>
#define MAX 1000001

using namespace std;

struct Answer {
    int start, end, range;
};

Answer ans = Answer{0, 0, MAX};

vector<int> solution(vector<int> seq, int k) {
    seq.insert(seq.begin(), 0);
    for(int i=1; i<seq.size(); i++) {
        seq[i] += seq[i-1];
    }
    
    int start = 0, end = 1;
    while(start <= end && end < seq.size()) {
        int diff = (start == end) ? seq[start] : seq[end] - seq[start];
        if(diff > k) {
            start++;
        } else {
            if(diff == k) {
                int range = end - start;
                if(range < ans.range) {
                    ans.start = start;
                    ans.end = end;
                    ans.range = range;
                }
            }
            end++;
        }
    }
    
    return {ans.start, ans.end-1};
}