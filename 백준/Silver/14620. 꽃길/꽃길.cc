//
//  꽃길.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 9/22/24.
//

#include <iostream>
#include <cmath>
using namespace std;

int N, ans=10e6;
int arr[11][11];
bool check[11][11];
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};

void initCheck(int x, int y, int d) {
    for(int dir=0; dir<d; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        check[nx][ny] = false;
    }
}

int calSum(int x, int y) {
    int sum = 0;
    for(int dir=0; dir<5; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(!check[nx][ny]) {
            sum += arr[nx][ny];
            check[nx][ny] = true;
        }
        else {
            initCheck(x, y, dir);
            return -1;
        }
    }
    return sum;
}

void dfs(int x, int y, int cnt, int sum) {
    if(cnt == 3) {
        ans = min(ans, sum);
        return;
    }
    
    for(int i=x; i<N-1; i++) {
        for(int j=1; j<N-1; j++) {
            if(check[i][j]) continue;
            int cur = calSum(i, j);
            if(cur != -1) {
                dfs(i, j, cnt+1, sum+cur);
                initCheck(i, j, 5);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=1; i<N-1; i++) {
        for(int j=1; j<N-1; j++) {
            int sum = calSum(i, j);
            dfs(i, j, 1, sum);
            initCheck(i, j, 5);
        }
    }
    
    cout << ans;
}
