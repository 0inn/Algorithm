#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
typedef long long ll;

int N, M, B;
ll IDT[MAX * 4];

void update(int n, ll x) {
	n += B - 1;
	IDT[n] = x;
	while (n /= 2) {
		IDT[n] = IDT[n * 2] + IDT[n * 2 + 1];
	}
}

ll lgSum(int l, int r) {
	l += B - 1;
	r += B - 1;
	ll sum = 0;
	while (l <= r) {
		if ((l % 2) == 1) sum += IDT[l];
		if ((r % 2) == 0) sum += IDT[r];
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (B = 1; B < N; B *= 2);
	for (int i = 0, a, b, c; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else {
			if (b > c) swap(b, c);	
			cout << lgSum(b, c) << "\n";
		}
	}

	return 0;
}
