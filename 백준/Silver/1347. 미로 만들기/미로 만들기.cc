//
//  미로 만들기.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 7/28/24.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string str;
bool arr[101][101] = {false, };

int dx[4] = {1, 0, -1, 0}; // 남 > 동 > 북 > 서
int dy[4] = {0, 1, 0, -1};

int rotate(char input, int dir) {
    int res = 0;
    switch (input) {
        case 'L':
            if(dir+1 == 4) res = 0;
            else res = dir+1;
            break;
        default:
            if(dir-1 == -1) res = 3;
            else res = dir-1;
            break;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> str;
    
    int x = 50, y = 50;
    int dir = 0;
    arr[x][y] = true;
    int stx = 50, sty = 50, enx = 50, eny = 50;
    for(int i=0 ; i<N; i++) {
        switch (str[i]) {
            case 'F':
                x += dx[dir];
                y += dy[dir];
                stx = min(stx, x);
                sty = min(sty, y);
                enx = max(enx, x);
                eny = max(eny, y);
                arr[x][y] = true;
                break;
            default:
                dir = rotate(str[i], dir);
                break;
        }
    }
    
    for(int i=stx; i<=enx; i++) {
        for(int j=sty; j<=eny; j++) {
            if(arr[i][j]) cout << ".";
            else cout << "#";
        }
        cout << "\n";
    }
}
