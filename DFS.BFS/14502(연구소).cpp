#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct info {
    int x, y;
};

int N, M, sum, ans;
int Map[9][9];
int MapTmp[9][9];
vector<info> arr;
vector<bool> temp;
queue<info> q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void virus() {
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (Map[nx][ny] != 0) continue;
            Map[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
            MapTmp[i][j] = Map[i][j];
            if (Map[i][j] == 0) {
                arr.push_back({i, j});
            }
            else if (Map[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
    
    for (int i = 0; i < arr.size(); i++) {
        if (i < arr.size() - 3) temp.push_back(false);
        else temp.push_back(true);
    }
    
    do {
        sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (temp[i]) {
                Map[arr[i].x][arr[i].y] = 1;
            }
        }
        virus();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (Map[i][j] == 0) sum++;
            }
        }
        ans = max(ans, sum);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Map[i][j] = MapTmp[i][j];
                if (Map[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
    } while(next_permutation(temp.begin(), temp.end()));
    
    cout << ans;
}
