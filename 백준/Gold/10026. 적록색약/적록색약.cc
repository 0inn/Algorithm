//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/10/10.
//

#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

struct Info {
    int x, y;
};

int N;
char arr[MAX][MAX];
bool check[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void input() {
    cin >> N;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
}

void cal_section(bool is_red_green, int x, int y) {
    queue<Info> q;
    q.push(Info{ x, y });
    check[x][y] = true;
    char cur_color = arr[x][y];
    
    while(!q.empty()) {
        Info cur = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(check[nx][ny]) continue;
            
            if(arr[nx][ny] == cur_color) {
                check[nx][ny] = true;
                q.push(Info{ nx, ny });
            } else if(is_red_green && cur_color != 'B' && arr[nx][ny] != 'B') {
                check[nx][ny] = true;
                q.push(Info{ nx, ny });
            }
        }
    }
}

int cal_count(bool is_red_green) {
    int cnt = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            check[i][j] = false;
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!check[i][j]) {
                cal_section(is_red_green, i, j);
                cnt++;
            }
        }
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    cout << cal_count(false) << " " << cal_count(true);
}
