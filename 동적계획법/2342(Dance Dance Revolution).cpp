#include<bits/stdc++.h>
using namespace std;

int N;
int dp[5][5][100001];
int arr[100001];

int ddr(int start, int end) {
	if (start == 0) return 2;	// 처음 시작
	if (start == end) return 1;	// 같은 곳 
	if (abs(start - end) == 2) return 4;	// 반대 방향
	return 3;	// 인접한 곳
}

int ans(int x, int y, int n) {
	if (n == N) return 0;
	if (dp[x][y][n] > 0) return dp[x][y][n];	// 메모이제이션

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