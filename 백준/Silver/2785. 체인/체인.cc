//
//  체인.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 12/2/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int N;
vector<ll> list;
int ans;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        ll L;
        cin >> L;
        list.push_back(L);
    }
    sort(list.begin(), list.end());
}

void solution() {
    int st = 0, en = N-1;
    
    while(st != en) {
        if(list[st] == 0) st++;
        else {
            list[st]--;
            en--;
            ans++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solution();
    
    cout << ans;
    return 0;
}
