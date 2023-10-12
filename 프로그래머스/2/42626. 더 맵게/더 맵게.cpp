#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int ans;
priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    for(auto s: scoville) {
        pq.push(s);
    }
    
    while(pq.size() > 1 && pq.top() < K) {
        int cur = pq.top();
        pq.pop();
        cur += (pq.top()*2);
        pq.pop();
        ans++;
        pq.push(cur);
    }

    return pq.top() < K ? -1 : ans;
}