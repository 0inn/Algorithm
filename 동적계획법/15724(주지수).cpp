#include <iostream>
using namespace std;

int N, M, K, ans;
int x1, y1, x2, y2;
int dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> dp[i][j];
            dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
        }
    }
    cin >> K;
    while(K--) {
        ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout << ans << "\n";
    }
}
