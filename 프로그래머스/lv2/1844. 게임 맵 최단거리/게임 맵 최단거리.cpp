#include<vector>
#include<queue>
#define MAX 101

using namespace std;

struct Point {
    int x, y;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dist[MAX][MAX];

int solution(vector<vector<int> > maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dist[i][j] = -1;
        }
    }
    
    queue<Point> q;
    q.push({0, 0});
    dist[0][0] = 1;
    while(!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
            if(maps[nx][ny] != 1 || dist[nx][ny] != -1) { continue; }
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
        }
    }
    
    return dist[n-1][m-1];
}