#include<bits/stdc++.h>
#define MAXC 100001
#define MAXN 101
using namespace std;

int N, M;
int m[MAXN];
int c[MAXN];
int dp[MAXN][MAXC];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> m[i];
	}
	int C = 0;
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		C += c[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= C; j++) {
			if (j >= c[i]) {	
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
			}
			else {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
		}
	}

	for (int i = 0; i <= C; i++) {
		if (dp[N][i] >= M) {
			cout << i;
			return 0;
		}
	}

	return 0;
}
