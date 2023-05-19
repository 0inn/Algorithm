//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/05/19.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 101

using namespace std;

struct Point {
    int x, y;
};

int N, K, R;
bool road[MAX][MAX][4];
bool check[MAX][MAX];
vector<Point> cow;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

void bfs(int x, int y) {
    queue<Point> q;
    q.push(Point{x, y});
    check[x][y] = true;
    
    while(!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(check[nx][ny] || road[cur.x][cur.y][dir]) continue;
            q.push(Point{nx, ny});
            check[nx][ny] = 1;
        }
    }
}

int main() {
    cin >> N >> K >> R;
    
    int x1, y1, x2, y2;
    for(int i=0; i<R; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        
        // 상하
        if(abs(x1-x2) == 1 && y1==y2) {
            if(x1 < x2) {
                road[x1][y1][2] = 1;
                road[x2][y2][0] = 1;
            }
            else {
                road[x1][y1][0] = 1;
                road[x2][y2][2] = 1;
            }
        }
        
        // 좌우
        if(abs(y1-y2) == 1 && x1==x2) {
            if(y1 < y2) {
                road[x1][y1][1] = 1;
                road[x2][y2][3] = 1;
            } else {
                road[x1][y1][3] = 1;
                road[x2][y2][1] = 1;
            }
        }
    }
    
    int x, y;
    for(int i=0; i<K; i++) {
        cin >> x >> y;
        cow.push_back(Point{x, y});
    }
    
    for(int i=0; i<cow.size(); i++) {
        memset(check, false, sizeof((check)));
        bfs(cow[i].x, cow[i].y);
        for(int j=i+1; j<cow.size(); j++) {
            if(!check[cow[j].x][cow[j].y]) ans += 1;
        }
    }
    
    cout << ans;
}
