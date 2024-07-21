//
//  컴백홈.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 7/21/24.
//

#include <iostream>
#include <string>

using namespace std;

int R, C, K, ans;
string arr[6];
bool check[6][6];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve(int i, int j, int d) {
    if(i == 0 && j ==C-1) {
        if(d == K) ans++;
        return;
    }
    
    for(int dir=0; dir<4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        
        if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
        if(arr[nx][ny] == 'T' || check[nx][ny]) continue;
        
        check[nx][ny] = true;
        solve(nx, ny, d+1);
        check[nx][ny] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> K;
    for(int i=0; i<R; i++) {
        cin >> arr[i];
    }
    
    check[R-1][0] = true;
    solve(R-1, 0, 1);
    
    cout << ans;
}
