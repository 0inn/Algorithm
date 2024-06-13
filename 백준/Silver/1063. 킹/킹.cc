//
//  킹.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 6/13/24.
//

#include <iostream>
#include <string>
#define KING 1
#define STONE 2

using namespace std;

struct Pos {
    int x, y;
};

int board[8][8];
int cnt;
Pos king, stone;

int format(int n) {
    return -(n-8);
}

string ansFormat(Pos pos) {
    string num = to_string(-pos.x+8);
    char alpha = pos.y+'A';
    return alpha+num;
}

void start() {
    string k, s;
    cin >> k >> s >> cnt;
    
    int i = format(k[1]-'0');
    int j = k[0]-'A';
    board[i][j] = KING;
    
    king = Pos{i, j};
    
    i = format(s[1]-'0');
    j = s[0]-'A';
    board[i][j] = STONE;
    
    stone = Pos{i, j};
}

void move(int dx, int dy) {
    int nx = king.x+dx, ny = king.y+dy;
    
    if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) return;
    if(board[nx][ny] == STONE) {
        int mx = nx+dx, my = ny+dy;
        if(mx < 0 || my < 0 || mx >= 8 || my >= 8) return;
        swap(board[nx][ny], board[mx][my]);
        stone = Pos{mx, my};
    }
    swap(board[king.x][king.y], board[nx][ny]);
    king = Pos{nx, ny};
}

void play() {
    string turn;
    while(cnt--) {
        cin >> turn;
        
        if(turn == "R") {
            move(0, 1);
        } else if(turn == "L") {
            move(0, -1);
        } else if(turn == "B") {
            move(1, 0);
        } else if(turn == "T") {
            move(-1, 0);
        } else if(turn == "RT") {
            move(-1, 1);
        } else if(turn == "LT") {
            move(-1, -1);
        } else if(turn == "RB") {
            move(1, 1);
        } else if(turn == "LB") {
            move(1, -1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    start();
    play();
    cout << ansFormat(king) << "\n" << ansFormat(stone);
}
