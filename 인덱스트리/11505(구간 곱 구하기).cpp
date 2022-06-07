#include<bits/stdc++.h>
#define MAX 1000001
#define MOD 1000000007
using namespace std;
typedef long long ll;

int N, M, K, B;
ll IDT[MAX * 4];

void initIDT() {
	for (int i = B - 1; i > 0; i--) {
		IDT[i] = (IDT[i * 2] * IDT[(i * 2) + 1]) % MOD;
	}
}

void update(int n, ll x) {
	n += B - 1;
	IDT[n] = x;
	while (n /= 2) {
		IDT[n] = (IDT[n * 2] * IDT[(n * 2) + 1]) % MOD;
	}
}

ll lgMul(int l, int r) {
	l += B - 1;
	r += B - 1;
	ll MUL = 1;
	while (l <= r) {
		if ((l % 2) == 1) MUL = (IDT[l] * MUL) % MOD;
		if ((r % 2) == 0) MUL = (IDT[r] * MUL) % MOD;
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return MUL;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (B = 1; B < N; B *= 2)
		memset(IDT, 1, sizeof(IDT));	
	for (int i = B; i < B + N; i++) {
		cin >> IDT[i];
	}
	initIDT();

	for (int i = 0, a, b, c; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << lgMul(b, c) << "\n";
	}

	return 0;
}
