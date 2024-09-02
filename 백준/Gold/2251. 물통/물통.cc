//
//  물통.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 9/2/24.
//

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int A, B, C;
bool check[201][201][201];
bool visited[201];
set<int> waters;

void dfs(int a, int b, int c) { // filled water
    if(check[a][b][c]) return;
    check[a][b][c] = true;
    
    if(a==0 && !visited[c]) {
        waters.insert(c);
        visited[c] = true;
    }
    
    int capA = A - a, capB = B - b, capC = C - c;
    dfs(max(0, a - capC), b, c + min(a, capC)); // a -> c
    dfs(max(0, a - capB), b + min(a, capB), c); // a -> b
    dfs(a, max(0, b - capC), c + min(b, capC)); // b -> c
    dfs(a + min(b, capA), max(0, b - capA), c); // b -> a
    dfs(a + min(c, capA), b, max(0, c - capA)); // c -> a
    dfs(a, b + min(c, capB), max(0, c - capB)); // c -> b
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B >> C;
    dfs(0, 0, C);
    for (auto water: waters) {
        cout << water << " ";
    }
}
