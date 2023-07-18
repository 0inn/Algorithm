//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/06/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

struct Point {
    int x, y;
};

int N, M;
int arr[51][51];
int dist[51][51];
vector<int> positions;
vector<int> v;
int ans = INF;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y) {
    queue<Point> q;
    q.push(Point{x, y});
    
    while(!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(arr[nx][ny] == 1 || dist[nx][ny] == 0) continue;
            if(dist[nx][ny] > dist[cur.x][cur.y] + 1) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void calculateTime(vector<int> v) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            dist[i][j] = INF;
        }
    }
    
    for(int i=0; i<v.size(); i++) {
        int x = v[i] / N;
        int y = v[i] % N;
        
        dist[x][y] = 0;
        bfs(x, y);
    }
    
    int result = -1;
    bool finish = false;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(dist[i][j] == INF) {
                if(arr[i][j] == 0 || arr[i][j] == 2) {
                    finish = true;
                }
                continue;
            }
            result = max(result, dist[i][j]);
        }
        if(finish) {
            result = -1;
            break;
        }
    }
    
    ans = (result == -1) ? ans : min(ans, result);
}

void selectVirusPosition(int k, vector<int> v) {
    if(v.size() == M) {
        calculateTime(v);
        return;
    }
    for(int i= k+1; i<positions.size(); i++) {
        v.push_back(positions[i]);
        selectVirusPosition(i, v);
        v.pop_back();
    }
    return;
}

void input() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
            
            if(arr[i][j] == 2) {
                positions.push_back(i*N+j);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    selectVirusPosition(-1, v);
    ans = (ans == INF) ? -1 : ans;
    cout << ans;
}
