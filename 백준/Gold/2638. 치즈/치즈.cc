//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/05/27.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int N, M, ans;
int zeroArr[101][101], arr[101][101];
bool zeroCheck[101][101], check[101][101];
vector<Point> ext;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 외부 공기 공간 구하기
void calExterior() {
    queue<Point> q;
    for(int i=0; i<ext.size(); i++) {
        q.push(ext[i]);
    }
    
    while(!q.empty()) {
        Point cur = q.front();
        zeroCheck[cur.x][cur.y] = true;
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(zeroCheck[nx][ny] || arr[nx][ny] == 1) continue;
            
            q.push({nx, ny});
            zeroCheck[nx][ny] = true;
        }
    }
}

// 치즈 녹이기
bool melting() {
    queue<Point> q;
    q.push(Point{0, 0});
    check[0][0] = true;
    int cnt = 0;
    
    while(!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(check[nx][ny]) continue;
            
            if(arr[nx][ny] == 0) q.push({nx, ny}); // 공기에 접촉한 경우 탐색
            else { // 치즈인 경우 녹일지 결정
                int zeroCnt = 0;
                for(int d=0; d<4; d++) {
                    int pnx = nx + dx[d];
                    int pny = ny + dy[d];
                    
                    if(zeroCheck[pnx][pny]) zeroCnt += 1;
                }
                
                if(zeroCnt >= 2) { // 두 변이 공기와 접촉하면 녹이기
                    arr[nx][ny] = 0;
                    ext.push_back(Point{nx, ny});
                    cnt += 1;
                }
            }
            
            check[nx][ny] = true;
        }
    }
    
    if(cnt == 0) return true;
    else {
        ans+=1;
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0 && ext.empty()) ext.push_back(Point{i, j});
        }
    }
    
    memset(zeroCheck, false, sizeof(zeroCheck));
    while(true) {
        calExterior();
        memset(check, false, sizeof(check));
        if(melting()) break;
    }
    
    cout << ans;
}
