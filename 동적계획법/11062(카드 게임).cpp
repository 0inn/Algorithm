#include<bits/stdc++.h>
using namespace std;

int T, N;
int card[1001];
int dp[1001][1001][2];

int game(int l, int r, bool turn) {
	if (dp[l][r][turn] != -1) return dp[l][r][turn];
	if (l == r) {
		if (turn) return dp[l][r][turn] = card[l];
		else return dp[l][r][turn] = 0;
	}
	if (turn) {
		dp[l][r][1] = max(game(l + 1, r, 0) + card[l], game(l, r - 1, 0) + card[r]);
	}
	else {
		dp[l][r][0] = min(game(l + 1, r, 1), game(l, r - 1, 1));
	}
	return dp[l][r][turn];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= N; i++) {
			cin >> card[i];
		}
		cout << game(1, N, 1) << "\n";
	}

	return 0;
}
