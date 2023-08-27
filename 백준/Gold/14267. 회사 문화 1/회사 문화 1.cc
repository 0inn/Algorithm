//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/08/27.
//

#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

struct Node {
    vector<int> under;
};

int n, m;
Node company[MAX];
int ans[MAX];
bool check[MAX];

void calculateAns(int cur, int boss) {
    check[cur] = true;
    for(int i=0; i<company[cur].under.size(); i++) {
        int under = company[cur].under[i];
        if(under != boss) {
            ans[under] += ans[cur];
            calculateAns(under, cur);
        }
    }
}

void input() {
    int upper;
    cin >> n >> m >> upper;
    
    for(int i=2; i<=n; i++) {
        cin >> upper;
        company[upper].under.push_back(i);
    }
    
    while(m--) {
        int i, w;
        cin >> i >> w;
        ans[i] += w;
    }
}

void output() {
    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    
    for(int i=1; i<=n; i++) {
        if(check[i]) continue;
        calculateAns(i, -1);
    }
    
    output();
}
