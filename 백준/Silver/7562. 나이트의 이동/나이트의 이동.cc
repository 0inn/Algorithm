//
//  나이트의 이동.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 12/13/24.
//

#include <iostream>
#include <queue>
using namespace std;

struct P {
    int x, y;
};

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2,-1, 1};

int bfs(int I, P st, P en) {
    queue <P> q;
    int dist[301][301];
    for(int i=0; i<301; i++) {
        for(int j=0; j<301; j++) {
            dist[i][j] = -1;
        }
    }
    
    q.push(st);
    dist[st.x][st.y] = 0;
    
    while(!q.empty()) {
        P cur = q.front();
        if(cur.x == en.x && cur.y == en.y) break;
        q.pop();
        
        for(int dir=0; dir<8; dir++) {
            P nxt = {cur.x + dx[dir], cur.y + dy[dir]};
            if(nxt.x < 0 || nxt.y < 0 || nxt.x >= I || nxt.y >= I) continue;
            if(dist[nxt.x][nxt.y] != -1) continue;
            
            q.push(nxt);
            dist[nxt.x][nxt.y] = dist[cur.x][cur.y] + 1;
        }
    }
    
    return dist[en.x][en.y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int I;
        cin >> I;
        
        P st, en;
        cin >> st.x >> st.y;
        cin >> en.x >> en.y;
        
        cout << bfs(I, st, en) << "\n";
    }
    
    return 0;
}
