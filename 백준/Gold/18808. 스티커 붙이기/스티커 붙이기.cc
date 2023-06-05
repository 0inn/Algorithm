//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/05/29.
//

#include <iostream>
#define MAX 101

using namespace std;

int N, M, K;
int n, m;
int note[MAX][MAX];
int r[MAX][MAX];
int ans;

// 90도 회전
void rotate() {
    int new_arr[MAX][MAX];
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            new_arr[i][j] = r[n-j-1][i];
        }
    }
    
    swap(n, m);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            r[i][j] = new_arr[i][j];
        }
    }
}

// 스티커 붙일 수 있는지 확인
bool findSpace(int x, int y) {
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+m; j++) {
            if(r[i-x][j-y] == 1 && note[i][j] != 0) return false;
        }
    }
    
    return true;
}

// 스티커 붙이기
void attachSticker(int x, int y) {
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+m; j++) {
            if(r[i-x][j-y] == 1) {
                note[i][j] = 1;
                ans += 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> N >> M >> K;
    
    for(int k=0; k<K; k++) {
        cin >> n >> m;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> r[i][j];
            }
        }
        
        int cnt = 0;
        int finish = false;
        
        while(!finish) {
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    if(i+n > N || j+m > M) continue;
                    
                    if(findSpace(i, j)) {
                        attachSticker(i, j);
                        finish = true;
                        break;
                    }
                }
                if(finish) break;
            }
            
            if(cnt == 3) break;
            rotate();
            cnt += 1;
        }
    }
    
    cout << ans << "\n";
}
