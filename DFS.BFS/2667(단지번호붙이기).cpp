#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct info {
    int x, y;
};

int N, cnt;
string MAP[26];
bool check[26][26];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<info> q;
vector<int> ans;


void bfs() {
    while(!q.empty()) {
        info cur = q.front();
        q.pop();
        cnt++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (check[nx][ny] || MAP[nx][ny] == '0') continue;
            check[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> MAP[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (MAP[i][j] == '1') {
                if (!check[i][j]) {
                    cnt = 0;
                    q.push({i, j});
                    check[i][j] = true;
                    bfs();
                    ans.push_back(cnt);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}
