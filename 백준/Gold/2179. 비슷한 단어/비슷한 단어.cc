//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/05/26.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, maxLen;
string arr[20001];
pair<string, string> ans;

void compareStrs() {
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            int cnt = 0;
            for(int l=0; l<arr[i].size(); l++) { // 접두사 비교
                if(arr[i][l] == arr[j][l]) cnt += 1;
                else break;
            }
            
            if(maxLen < cnt) {
                maxLen = cnt;
                ans.first = arr[i];
                ans.second = arr[j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    compareStrs();
    
    cout << ans.first << "\n" << ans.second;
}
