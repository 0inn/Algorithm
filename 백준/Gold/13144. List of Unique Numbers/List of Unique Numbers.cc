//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/10/04.
//

#include <iostream>
#include <map>
#define MAX 100001
typedef long long ll;

using namespace std;

ll N, ans;
ll arr[MAX] = {};
map<ll, int> dict;

void select_seq() {
    int start = 0, end = 0;
    dict[arr[start]] = 1;
    
    while(start < N) {
        while(end < N-1 && dict[arr[end+1]] == 0) {
            end++;
            dict[arr[end]]++;
        }
        
        dict[arr[start]] -= 1;
        ans += (end - start) + 1;
        start++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    select_seq();
    
    cout << ans;
}
