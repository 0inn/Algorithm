#include<bits/stdc++.h>
using namespace std;

int n;
int dp[1001];

// 길이가 1 증가했을 때의 상황을 생각 !
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