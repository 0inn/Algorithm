#include<bits/stdc++.h>
using namespace std;

int N;
int P[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	dp[1] = P[1];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], P[j] + dp[i - j]);
		}
	}

	cout << dp[N];

	return 0;
}