#include <iostream>
#include <algorithm>
using namespace std;

int R, C, cnt;
int is, ie, js, je;
string board[11];
string ans[11];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    cin >> R >> C;
    is = 11;
    js = 11;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++) {
            ans[i][j] = '.';
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'X') {
                cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int x = i + dx[dir];
                    int y = j + dy[dir];
                    if (board[x][y] == '.' || x < 0 || x >= R || y < 0 || y >= C ) {
                        cnt++;
                    }
                }
                if (cnt < 3) {
                    ans[i][j] = 'X';
                    is = min(is, i);
                    ie = max(ie, i);
                    js = min(js, j);
                    je = max(je, j);
                }
            }
        }
    }
    
    for (int i = is; i <= ie; i++) {
        for (int j = js; j <= je; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
