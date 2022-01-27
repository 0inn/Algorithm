#include<bits/stdc++.h>
using namespace std;

int T, N;
int card[1001];
int dp[1001][1001][2];
// dp[l][r][1] : l ~ r 카드 + 근우차례일 때, 근우가 얻게 되는 최대점수
// dp[l][r][0] : l ~ r 카드 + 명우차례일 때, 근우가 얻게 되는 최대점수

int game(int l, int r, bool turn) {	// 근우 차례 1
	if (dp[l][r][turn] != -1) return dp[l][r][turn];	// 이미 구해진 값은 계산하지 않음
	if (l == r) {	// 카드 한장 남았을 때
		if (turn) return dp[l][r][turn] = card[l];
		else return dp[l][r][turn] = 0;
	}
	if (turn) {	// 근우 차례일 때, 카드 하나의 점수 더하고, 근우의 점수 최댓값
		dp[l][r][1] = max(game(l + 1, r, 0) + card[l], game(l, r - 1, 0) + card[r]);
	}
	else {	// 명우 차례일 때, 카드 하나 빼고, 근우의 점수 최솟값
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
		memset(dp, -1, sizeof(dp));	// dp -1로 초기화
		for (int i = 1; i <= N; i++) {
			cin >> card[i];
		}
		cout << game(1, N, 1) << "\n";
	}

	return 0;
}