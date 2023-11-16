//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/16.
//

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100001

using namespace std;

int N, ans;
priority_queue<int, vector<int>, greater<int>> cards;

void input() {
    cin >> N;
    
    int cnt;
    while(N--) {
        cin >> cnt;
        cards.push(cnt);
    }
}

int get_cards_cnt() {
    if(cards.empty()) return 0;
    int cnt = cards.top();
    cards.pop();
    return cnt;
}

void cal_min_count() {
    while(true) {
        int first = get_cards_cnt();
        int second = get_cards_cnt();
        if(first == 0 || second == 0) break;
        int cur = first + second;
        ans += cur;
        if(cards.empty()) break;
        cards.push(cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    cal_min_count();
    cout << ans;
}
