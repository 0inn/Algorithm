#include <iostream>
#include <vector>
using namespace std;

struct info {
    int x, y;
};

int N, M, d, s, ans;
int A[51][51];
bool check[51][51];
vector<info> cloud;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void checkCloud() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            check[i][j] = false;
        }
    }
    for (int i = 0; i < cloud.size(); i++) {
        check[cloud[i].x][cloud[i].y] = true;
    }
}

void makeCloud() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] >= 2 && !check[i][j]) {
                cloud.push_back({i, j});
                A[i][j] -= 2;
            }
        }
    }
}

void moveCloud(int d, int s) {
    for (int i = 0; i < cloud.size(); i++) {
        int nx = cloud[i].x + (dx[d-1] * s);
        int ny = cloud[i].y + (dy[d-1] * s);
        while(nx < 0) {
            nx += N;
        }
        while(ny < 0) {
            ny += N;
        }
        while (nx >= N) {
            nx -= N;
        }
        while (ny >= N) {
            ny -= N;
        }
        cloud[i].x = nx;
        cloud[i].y = ny;
    }
    for (int i = 0; i < cloud.size(); i++) {
        A[cloud[i].x][cloud[i].y]++;
    }
    checkCloud();
}

void plusWater() {
    for (int i = 0; i < cloud.size(); i++) {
        int cnt = 0;
        for (int dir = 1; dir < 8; dir+=2) {
            int nx = cloud[i].x + dx[dir];
            int ny = cloud[i].y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (A[nx][ny] > 0) cnt++;
        }
        A[cloud[i].x][cloud[i].y] += cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            if (i > N - 3 && j < 2) {
                cloud.push_back({i, j});
            }
        }
    }
    cin >> d >> s;
    moveCloud(d, s);
    plusWater();
    cloud.clear();
    makeCloud();
    for (int i = 1; i < M; i++) {
        cin >> d >> s;
        moveCloud(d, s);
        plusWater();
        cloud.clear();
        makeCloud();
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += A[i][j];
        }
    }
    cout << ans;
}
