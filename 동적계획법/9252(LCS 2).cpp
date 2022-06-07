#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

string str1, str2;
int dp[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str1 >> str2;
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int x = str1.size();
	int y = str2.size();
	cout << dp[x][y] << "\n";
	if (dp[x][y] == 0) {
		return 0;
	}
    
    
	vector<char> ans;
	while (true) {
		if (x == 0 || y == 0) break;	
		if (str1[x - 1] == str2[y - 1]) {
			ans.push_back(str1[x - 1]);
			x--;
			y--;
		}
		else if (dp[x][y] == dp[x][y - 1]) y--;
		else x--;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}

	return 0;
}
