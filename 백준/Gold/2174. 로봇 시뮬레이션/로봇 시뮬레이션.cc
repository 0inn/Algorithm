//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/05/26.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Robot {
    int num = 0;
    int dir = -1;
};

struct Point {
    int x, y;
};

int A, B, N, M;
Robot arr[101][101];
vector<Point> robots;
bool isFinished;

// 북 동 남 서
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 명령 수행
void move(int num, char cmd, int cnt) {
    int nx = robots[num].x;
    int ny = robots[num].y;
    int dir = arr[nx][ny].dir;
    
    if(cmd == 'L') { // 왼쪽으로 90도 회전
        while(cnt--) {
            arr[nx][ny].dir -= 1;
            if(arr[nx][ny].dir < 0) arr[nx][ny].dir = 3;
        }
    
    } else if(cmd == 'R') { // 오른쪽으로 90도 회전
        dir += cnt;
        dir %= 4;
        arr[nx][ny].dir = dir;
    } else { // 향하고 있는 방향으로 한 칸 움직임
        arr[nx][ny].dir = -1;
        
        for(int i=0; i<cnt; i++) {
            nx += dx[dir];
            ny += dy[dir];
            
            if(nx<=0 || ny<=0 || nx>B || ny>A) { // 벽에 충돌하는 경우
                cout << "Robot " << num+1 << " crashes into the wall";
                isFinished = true;
                return;
            }
            if(arr[nx][ny].dir != -1) { // 다른 로봇에 충돌하는 경우
                cout << "Robot " << num+1 << " crashes into robot " << arr[nx][ny].num+1;
                isFinished = true;
                return;
            }
        }
        
        arr[nx][ny].dir = dir;
        arr[nx][ny].num = num;
        
        robots[num].x = nx;
        robots[num].y = ny;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> A >> B >> N >> M;
    
    int x, y, dir;
    char d;
    for(int i=0; i<N; i++) {
        cin >> y >> x >> d;
        
        if(d == 'N') dir = 0;
        else if(d == 'E') dir = 1;
        else if(d == 'S') dir = 2;
        else dir = 3;
        
        arr[x][y].num = i;
        arr[x][y].dir = dir;
        robots.push_back(Point{x, y});
    }
    
    int num, cnt;
    char cmd;
    for(int i=0; i<M; i++) {
        cin >> num >> cmd >> cnt;
        move(num-1, cmd, cnt);
        if(isFinished) return 0;
    }
    
    cout << "OK";
}
