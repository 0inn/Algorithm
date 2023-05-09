#include<bits/stdc++.h>
using namespace std;

int n;
int dp[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n];

}