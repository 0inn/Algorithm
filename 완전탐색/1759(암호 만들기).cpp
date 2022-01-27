#include<bits/stdc++.h>
using namespace std;

int L, C;
vector<char> pw;
vector<bool> tmp;

// 최소 한 개의 모음과 최소 두 개의 자음
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> L >> C;
	char c;
	for (int i = 0; i < C; i++) {
		cin >> c;
		pw.push_back(c);
		tmp.push_back(true);
	}
	sort(pw.begin(), pw.end());

	// 6C4 : {f,f,f,f,t,t}
	for (int i = 0; i < L; i++) {
		tmp[i] = false;
	}

	do {
		int x = 0, y = 0;
		string s;
		for (int i = 0; i < C; i++) {
			if (!tmp[i]) {
				if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' 
					|| pw[i] == 'o' || pw[i] == 'u') x++;
				else y++;
				s += pw[i];
			}
			if (i == C - 1) {
				if (x > 0 && y > 1) cout << s << "\n";
			}
		}
	} while (next_permutation(tmp.begin(), tmp.end()));

	return 0;
}