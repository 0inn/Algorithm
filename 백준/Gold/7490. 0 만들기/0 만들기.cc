//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/09/13.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<string> ans;

void dfs(int n, int sum, string exp) {
    if(n==N+1) {
        if(sum==0) {
            ans.push_back(exp.substr(1));
        }
        return;
    }
    dfs(n+1, sum+(n), exp+"+"+to_string(n));
    if(n<=N-1) dfs(n+2, sum+(n*10)+(n+1), exp+"+"+to_string(n)+" "+to_string(n+1));
    
    if(n==1) return;
    
    dfs(n+1, sum-(n), exp+"-"+to_string(n));
    if(n<=N-1) dfs(n+2, sum-(n*10)-(n+1), exp+"-"+to_string(n)+" "+to_string(n+1));
}

void solution() {
    cin >> T;
    
    while(T--) {
        cin >> N;
        dfs(1, 0, "");
        sort(ans.begin(), ans.end());
        for(auto ans_exp: ans) cout << ans_exp << "\n";
        cout << "\n";
        ans.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solution();
}
