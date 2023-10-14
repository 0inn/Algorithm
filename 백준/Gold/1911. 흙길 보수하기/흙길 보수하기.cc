//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/10/14.
//

#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;

using namespace std;

struct Water {
    ll s, e;
};

struct cmp {
    bool operator()(Water w1, Water w2) {
        return w1.s > w2.s;
    }
};

ll N, L, idx, ans;
priority_queue<Water, vector<Water>, cmp> pq;

void input() {
    cin >> N >> L;
    
    ll s, e;
    while(N--) {
        cin >> s >> e;
        if(s > e) swap(s, e);
        pq.push(Water{ s, e });
    }
}

bool has_rest(ll diff) {
    return !(diff%L == 0);
}

void calculate_ans() {
    idx = 0;
    
    while(!pq.empty()) {
        Water cur = pq.top();
        pq.pop();
        
        ll diff, cnt, nxt;
        if(cur.s > idx) { // 새로 널빤지 깔기
            diff = cur.e - cur.s;
            cnt = diff/L + has_rest(diff);
            nxt = cur.s + cnt*L;
        } else { // 이어서 널빤지 깔기
            diff = cur.e - idx;
            if(diff < 0) continue;
            cnt = diff/L + has_rest(diff);
            nxt = idx + cnt*L;
        }
        idx = nxt;
        
        ans += cnt;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    calculate_ans();
    cout << ans;
}
