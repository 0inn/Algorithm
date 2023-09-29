#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
typedef long long ll;

using namespace std;

priority_queue<int> pq;
ll ans;

ll solution(int n, vector<int> works) {
    
    for(int i=0; i<works.size(); i++) {
        pq.push(works[i]);
    }
    
    while(n--) {
        int work = pq.top();
        pq.pop();
        if(work > 0) work--;
        pq.push(work);
    }
    
    while(!pq.empty()) {
        ans += pow(pq.top(), 2);
        pq.pop();
    }
    
    return ans;
}