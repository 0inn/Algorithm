//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/12/02.
//

#include <iostream>
#include <algorithm>
#include <limits.h>
#define MAX 51
using namespace std;

int n, m;
char board[MAX][MAX];

void input() {
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
}

int make_chess(int x, int y, bool is_w) {
    int cnt = 0;
    
    for(int i=x; i<x+8; i++) {
        for(int j=y; j<y+8; j++) {
            if(i%2 == 0) { // 짝수 행
                if(j%2 == 0) { // 짝수 열
                    if(is_w && board[i][j] != 'W') cnt++;
                    if(!is_w && board[i][j] != 'B') cnt++;
                } else {
                    if(is_w && board[i][j] != 'B') cnt++;
                    if(!is_w && board[i][j] != 'W') cnt++;
                }
            } else { // 홀수 행
                if(j%2 != 0) { // 홀수 열
                    if(is_w && board[i][j] != 'W') cnt++;
                    if(!is_w && board[i][j] != 'B') cnt++;
                } else {
                    if(is_w && board[i][j] != 'B') cnt++;
                    if(!is_w && board[i][j] != 'W') cnt++;
                }
            }
        }
    }
    
    return cnt;
}

int choose_board() {
    int ans = INT_MAX;
    
    for(int i=0; i<=n-8; i++) {
        for(int j=0; j<=m-8; j++) {
            ans = min(ans, make_chess(i, j, true));
            ans = min(ans, make_chess(i, j, false));
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    cout << choose_board();
}
