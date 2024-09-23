//
//  로봇.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 9/22/24.
//

#include <iostream>
using namespace std;

int r, c, k, sr, sc;
int arr[1001][1001];
int dir[4];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct Point {
    int x, y;
};
Point nxt[4] = {Point{-1, 0}, Point{1, 0}, Point{0, -1}, Point{0, 1}};

Point move(int x, int y, int dir) {
    int nx = x+nxt[dir].x;
    int ny = y+nxt[dir].y;
    if(nx < 0 || ny < 0 || nx >= r || ny >= c || arr[nx][ny] != 0) return Point{x, y};
    return Point{nx, ny};
}

bool isTurn(int x, int y, int dir) {
    int nx = x+nxt[dir].x;
    int ny = y+nxt[dir].y;
    if(nx < 0 || ny < 0 || nx >= r || ny >= c || arr[nx][ny] != 0) return true;
    return false;
}

bool isEnd(int x, int y) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if(arr[nx][ny] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c >> k;
    
    int br, bc;
    while(k--) {
        cin >> br >> bc;
        arr[br][bc] = 1;
    }
    
    cin >> sr >> sc;
    for(int i=0; i<4; i++) {
        cin >> dir[i];
        dir[i]--;
    }
    
    Point ans = Point{sr, sc};
    int curd = 0;
    arr[ans.x][ans.y] = 1;
    while(!isEnd(ans.x, ans.y)) {
        while(!isTurn(ans.x, ans.y, dir[curd])) {
            Point nxt = move(ans.x, ans.y, dir[curd]);
            arr[nxt.x][nxt.y] = 1;
            ans = nxt;
        }
        curd++;
        if(curd == 4) curd = 0;
    }
    
    cout << ans.x << " " << ans.y;
}
