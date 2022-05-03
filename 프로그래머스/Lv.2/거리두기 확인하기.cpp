//
//  거리두기 확인하기.cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/05/02.
//

#include <bits/stdc++.h>
using namespace std;

struct info {
    int x, y, d;    // x좌표, y좌표, 맨해튼 거리
};

vector<string> place;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool bfs(int x, int y) {
    bool check[5][5] = {false, };
    queue<info> q;
    q.push({x, y, 0});
    check[x][y] = true;
    
    while(!q.empty()) {
        info cur = q.front();
        q.pop();
        if (cur.d == 2) continue;   // 맨해튼 거리 2보다 큰 경우, 탐색할 필요 X
        
        for (int dir=0; dir<4; dir++) {
            int nx = dx[dir] + cur.x;
            int ny = dy[dir] + cur.y;
            
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;
            if (check[nx][ny] || place[nx][ny] == 'X') // 방문했거나, 파티션 존재하면 탐색 X
                continue;
            if (place[nx][ny] == 'P') { // 맨해튼 거리가 2이하고, 응시자가 앉았다면, 실패
                return false;
            }
            
            q.push({nx, ny, cur.d+1});
            check[nx][ny] = true;
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int x=0; x<5; x++) {
        bool flag = true;    // 거리두기 성공으로 설정
        place = places[x];  // 대기실 한 개
        
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (place[i][j] == 'P') {   // P인 경우 bfs 탐색
                    if (!bfs(i, j)) flag = false;    // 거리두기 실패하면 flag 바꿈
                    break;
                }
            }
            if (!flag) break;
        }
        
        if (flag) { answer.push_back(1); }  // 거리두기 성공
        else { answer.push_back(0); }   // 거리두기 실패
    }
    
    
    return answer;
}
