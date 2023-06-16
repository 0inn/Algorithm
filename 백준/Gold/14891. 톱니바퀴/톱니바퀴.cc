//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/06/16.
//

#include <iostream>
#include <string>

using namespace std;

int K;
string wheel[5];
char reach[7];
bool r_wheel[5];
int idx[5], dir_wheel[5];
int n, dir, ans;

// 각 톱니바퀴 회전 방향 계산
void check_dir() {
    for(int i=1; i<=4; i++) {
        dir_wheel[i] = 0;
        r_wheel[i] = false;
    }
    
    dir_wheel[n] = dir;
    r_wheel[n] = true;
    
    int left = n, right = n;
    
    while(true) {
        left--;
        right++;
        
        if(left < 1 && right > 4) break;
        
        int nxt = left+1;
        if(left >= 1) {
            // 회전 가능 여부 판단
            if(wheel[nxt][(idx[nxt]+6)%8] != wheel[left][(idx[left]+2)%8]) r_wheel[left] = true;
            else left = 0;
            
            if(dir_wheel[nxt] == 1) dir_wheel[left] = -1;
            else dir_wheel[left] = 1;
        }
        
        nxt = right-1;
        if(right <= 4) {
            // 회전 가능 여부 판단
            if(wheel[nxt][(idx[nxt]+2)%8] != wheel[right][(idx[right]+6)%8]) r_wheel[right] = true;
            else right = 4;
            
            if(dir_wheel[nxt] == 1) dir_wheel[right] = -1;
            else dir_wheel[right] = 1;
        }
    }
}

// 톱니바퀴 회전
void rotate_wheel() {
    for(int i=1; i<=4; i++) {
        if(!r_wheel[i]) continue;
        
        if(dir_wheel[i] == 1) { // 시계 방향
            if(idx[i]==0) idx[i] = 7;
            else idx[i] -= 1;
        } else { // 반시계 방향
            if(idx[i] == 7) idx[i] = 0;
            else idx[i] += 1;
        }
    }
}

// 정답 계산
void sol() {
    int mul = 1;
    
    for(int i=1; i<=4; i++) {
        if(wheel[i][idx[i]] == '1') {
            ans += mul;
        }
        mul *= 2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    for(int i=1; i<=4; i++) {
        cin >> wheel[i];
    }
    
    cin >> K;
    
    for(int i=0; i<K; i++) {
        cin >> n >> dir;
        
        check_dir();
        rotate_wheel();
    }
    
    sol();
    
    cout << ans;
}
