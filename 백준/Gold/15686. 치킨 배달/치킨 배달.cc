//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/08/07.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int N, M;
int ans = 1e9;
int arr[51][51];
bool check[51][51];
bool is_chicken[51][51] = { false, };
vector<Point> v, homes, chickens;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int calculate_dist() {
    int total = 0;
    
    for(int i=0; i<homes.size(); i++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                check[i][j] = false;
            }
        }
        Point start = homes[i];
        queue<Point> q;
        q.push(start);
        check[start.x][start.y] = true;
        
        while(!q.empty()) {
            Point cur = q.front();
            q.pop();
            
            for(int dir=0; dir<4; dir++) {
                int nx = dx[dir] + cur.x;
                int ny = dy[dir] + cur.y;
                
                if(nx < 0 || ny < 0 || nx >= N || ny >= N || check[nx][ny]) { continue; }
                if(is_chicken[nx][ny]) {
                    total += abs(nx-start.x) + abs(ny-start.y);
                    q = queue<Point>();
                    break;
                }
                check[nx][ny] = true;
                q.push(Point{nx, ny});
            }
        }
    }
    
    return total;
}

void select_chickens(int k, vector<Point> v) {
    if(v.size() == M) {
        ans = min(ans, calculate_dist());
        return;
    }
    
    for(int i=k+1; i<chickens.size(); i++) {
        v.push_back(chickens[i]);
        is_chicken[chickens[i].x][chickens[i].y] = true;
        select_chickens(i, v);
        is_chicken[v.back().x][v.back().y] = false;
        v.pop_back();
    }
    return;
}

void input() {
    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                homes.push_back(Point{i, j});
            }
            if(arr[i][j] == 2) {
                chickens.push_back(Point{i, j});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    select_chickens(-1, v);
    cout << ans;
}
