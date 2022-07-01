#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct info {
    int x, y;
};

int N, L, R, sum, ans;
int A[51][51];
queue<info> q;
vector<info> v;
bool check[51][51];
bool moveFlag;
bool ansFlag;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int move (int a, int b) {
    int tmp = abs(a - b);
    if (tmp >= L && tmp <= R) {
        return tmp;
    }
    return 0;
}

void solution() {
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        v.push_back({cur.x, cur.y});
        sum += A[cur.x][cur.y];
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx >= N || ny >= N || nx < 0 || ny < 0) continue;
            if (check[nx][ny]) continue;
            int d = move(A[cur.x][cur.y], A[nx][ny]);
            if (d != 0) {
                moveFlag = true;
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    
    while (true) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                check[i][j] = false;
            }
        }
        ansFlag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!check[i][j]) {
                    v.clear();
                    sum = 0;
                    moveFlag = false;
                    q.push({i, j});
                    check[i][j] = true;
                    solution();
                    if (moveFlag) {
                        ansFlag = true;
                        for (int z = 0; z < v.size(); z++) {
                            A[v[z].x][v[z].y] = sum / v.size();
                        }
                    }
                }
            }
        }
        if (ansFlag) ans++;
        else break;
    }
    
    cout << ans;
}
