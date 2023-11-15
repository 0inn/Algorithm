//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/15.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, ans;
vector<int> man_plus, man_minus;
vector<int> woman_plus, woman_minus;

void input() {
    cin >> N;
    
    for(int i=0, h; i<N; i++) {
        cin >> h;
        if(h > 0) man_plus.push_back(h);
        else man_minus.push_back(abs(h));
    }
    
    for(int i=0, h; i<N; i++) {
        cin >> h;
        if(h > 0) woman_plus.push_back(h);
        else woman_minus.push_back(abs(h));
    }
}

void sort_heights() {
    sort(man_plus.begin(), man_plus.end());
    sort(woman_plus.begin(), woman_plus.end());
    sort(man_minus.begin(), man_minus.end());
    sort(woman_minus.begin(), woman_minus.end());
}

void make_pairs(vector<int> minus, vector<int> plus) {
    int m = 0, p = 0;
    while(m < minus.size() && p < plus.size()) {
        if(abs(minus[m]) > abs(plus[p])) {
            ans++;
            p++;
        }
        m++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    sort_heights();
    make_pairs(man_minus, woman_plus);
    make_pairs(woman_minus, man_plus);
    cout << ans;
}
