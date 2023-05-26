//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/05/26.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Point {
    int x, y;
};

int N, M;
int arr[101][101];
bool check[101][101];
int ans, total, cnt;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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
            
            if(arr[nx][ny] == 0) { // 치즈 없는 칸인 경우 탐색
                q.push(Point{nx, ny});
            } else { // 치즈 있는 칸인 경우 녹이기
                arr[nx][ny] = 0;
                cnt += 1;
            }
            check[nx][ny] = true;
        }
    }
    
    if(cnt == 0) { // 전부 다 녹인 경우
        cout << ans << "\n" << total;
        return true;
    } else {
        ans += 1;
        total = cnt;
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
        }
    }
    
    while(!melting()) {
        memset(check, false, sizeof(check));
    }
}
