#include<bits/stdc++.h>
using namespace std;

int N;
int dp[5][5][100001];
int arr[100001];

int ddr(int start, int end) {
	if (start == 0) return 2;
	if (start == end) return 1;
	if (abs(start - end) == 2) return 4;
	return 3;
}

int ans(int x, int y, int n) {
	if (n == N) return 0;
	if (dp[x][y][n] > 0) return dp[x][y][n];	

	int left = ans(arr[n], y, n + 1) + ddr(x, arr[n]);
	int right = ans(x, arr[n], n + 1) + ddr(y, arr[n]);
	return dp[x][y][n] = min(left, right);
}

int main() {
	while (true) {
		cin >> arr[N];
		if (arr[N] == 0) break;
		N++;
	}
	cout << ans(0, 0, 0);

	return 0;
}
