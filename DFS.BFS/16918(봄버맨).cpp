#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct info {
    int x, y;
};

int R, C, N;
string str;
vector<string> bomb;
queue<info> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        cin >> str;
        bomb.push_back(str);
    }
    
    for (int k = 2; k <= N; k++) {
        if (k % 2 == 0) {   // 짝수초: 폭탄 채우기
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (bomb[i][j] == 'O') q.push({i, j});
                    else bomb[i][j] = 'O';
                }
            }
        }
        else {  // 홀수초: 폭탄 터뜨리기
            while (!q.empty()) {
                info cur = q.front();
                q.pop();
                bomb[cur.x][cur.y] = '.';
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                    if (bomb[nx][ny] == 'O') bomb[nx][ny] = '.';
                }
            }
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << bomb[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
