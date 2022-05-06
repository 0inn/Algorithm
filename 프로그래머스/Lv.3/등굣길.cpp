//
//  등굣길.cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/05/06.
//

#include <bits/stdc++.h>
using namespace std;

int board[101][101];
bool isPud[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    
    for (int i = 0; i < puddles.size(); i++) {
        isPud[puddles[i][1]][puddles[i][0]] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!isPud[i][1]) {
            board[i][1] = 1;
        } else {
            break;
        }
    }
    for (int j = 1; j <= m; j++) {
        if (!isPud[1][j]) {
            board[1][j] = 1;
        } else {
            break;
        }
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (!isPud[i][j]) {
                board[i][j] = (board[i-1][j] + board[i][j-1]) % 1000000007;
            }
        }
    }
    
    return board[n][m];
}
