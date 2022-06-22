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
int sec[201][201];  // 폭탄 설치한 시간
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<info> q, q2;
queue<info> q_tmp, q_tmp2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        cin >> str;
        bomb.push_back(str);
        for (int j = 0; j < C; j++) {
            if (bomb[i][j] == 'O') sec[i][j] = 0;
            else sec[i][j] = 2;
        }
    }
    
    for (int k = 2; k < N; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (sec[i][j] == k - 2) {
                    sec[i][j] = k + 1;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                        sec[nx][ny] = k + 1;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << sec[i][j];
            //if (sec[i][j] == N) cout << '.';
            //else cout << 'O';
        }
        cout << "\n";
    }
}
