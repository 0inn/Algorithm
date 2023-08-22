//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/08/22.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100001];
int ans;

void input() {
    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
}

void solution() {
    sort(arr, arr+N);
    ans = arr[N-1] - arr[0];
    
    int start = 0, end = 0;
    while(end < N) {
        int diff = arr[end] - arr[start];
        
        if(diff < M) {
            end++;
        } else {
            ans = min(ans, diff);
            start++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solution();
    cout << ans;
}
