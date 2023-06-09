//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/06/09.
//

#include <iostream>
#include <map>
#include <algorithm>
#define MAX 60001

using namespace std;

int N, d, k, c;
int arr[MAX];
map<int, int> sushi;

// 초밥 존재하는지 확인
bool is_exist_sushi(int i) {
    if(sushi.find(i) != sushi.end()) return true;
    return false;
}

// 초밥 가짓수의 최댓값 계산
int cal_max() {
    int max_cnt = 0, cnt = 0;
    int start = 0, end = k-1;
    
    for(int i=0; i<k; i++) {
        if(arr[i] == c) continue;
        if(!is_exist_sushi(arr[i])) {
            cnt++;
            sushi.insert({arr[i], 1});
        } else {
            sushi[arr[i]]++;
        }
    }
    
    while(end < 2*N-2) {
        max_cnt = max(cnt, max_cnt);
        
        int cur_sushi = arr[start];
        if(sushi[cur_sushi] == 1) {
            cnt--;
            sushi.erase(cur_sushi);
        } else sushi[cur_sushi]--;
        start++;
        
        end++;
        int nxt_sushi = arr[end];
        if(nxt_sushi != c) {
            if(!is_exist_sushi(nxt_sushi)) {
                cnt++;
                sushi.insert({nxt_sushi, 1});
            } else sushi[nxt_sushi]++;
        }
    }
    
    return max_cnt + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> N >> d >> k >> c;
    
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    // 원형배열 생성
    for(int i=N; i<2*N-1; i++) {
        arr[i] = arr[i-N];
    }
    
    cout << cal_max();
}
