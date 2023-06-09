//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/06/05.
//

#include <iostream>
#include <vector>

using namespace std;

struct Chess {
    int n, dir; // 체스 번호, 방향
};

struct Point {
    int x, y, dir;
    bool possible;
};

int N, K, ans;
int type_arr[13][13];
vector<Chess> arr[13][13];
Point num[11];

// 우 좌 상 하
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

vector<Chess> tmp;

void move(int x, int y, int nx, int ny, int dir) {
    while(!arr[x][y].empty()) {
        tmp.push_back(Chess{arr[x][y].back().n, arr[x][y].back().dir});
        arr[x][y].pop_back();
    }
    
    if(type_arr[nx][ny] == 1) { // 빨간색
        for(int i=0; i<tmp.size(); i++) {
            arr[nx][ny].push_back(tmp[i]);
            num[tmp[i].n] = Point{nx, ny, tmp[i].dir, false};
        }
    } else { // 흰색
        for(int i=tmp.size()-1; i>=0; i--) {
            arr[nx][ny].push_back(tmp[i]);
            num[tmp[i].n] = Point{nx, ny, tmp[i].dir, false};
        }
    }
    num[arr[nx][ny][0].n].possible = true;
}

// 1 ~ K 까지 게임 시작
bool play_game() {
    for(int i=1; i<=K; i++) {
        if(!num[i].possible) continue; // 가장 아래에 있는 말이 아닐경우 제외
        
        int x = num[i].x;
        int y = num[i].y;
        int dir = num[i].dir;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // 파란색이거나 범위 벗어난 경우
        if((nx <= 0 || ny <= 0 || nx > N || ny > N) || (type_arr[nx][ny] == 2)) {
            // 방향 바꾸기
            int dir = arr[x][y][0].dir;
            if(dir == 0 || dir == 2) dir += 1;
            else dir -= 1;
            
            arr[x][y][0].dir = dir;
            nx = x + dx[dir];
            ny = y + dy[dir];
            num[arr[x][y][0].n] = Point{x, y, dir, true};
            
            if(nx <= 0 || ny <= 0 || nx > N || ny > N) continue; // 범위 벗어난 경우 제외
            if(type_arr[nx][ny] == 2) continue; // 다음 칸이 파란색인 경우 제외
        }
        
        // 한 칸 이동하기
        move(x, y, nx, ny, dir);
        
        // 말이 4개 이상 쌓이는 순간 게임 종료
        if(arr[nx][ny].size() >= 4) return true;
        tmp.clear();
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> N >> K;
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> type_arr[i][j];
        }
    }
    
    int x, y, dir;
    for(int i=0; i<K; i++) {
        cin >> x >> y >> dir;
        arr[x][y].push_back(Chess{i+1, dir-1});
        num[i+1] = Point{x, y, dir-1, true};
    }
    
    // 턴 진행
    ans = 1;
    while(!play_game()) {
        ans++;
        if(ans > 1000) {
            ans = -1;
            break;
        }
    }
    
    cout << ans;
}
