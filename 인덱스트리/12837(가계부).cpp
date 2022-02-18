#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
typedef long long ll;

int N, Q, B;
ll IDT[MAX * 4];

void add(int n, ll p) {	// 변경이 아닌 "추가"
	n += B - 1;
	IDT[n] += p;
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

	cin >> N >> Q;
	for (B = 1; B < N; B *= 2);
	for (int i = 0, n, p, x, q; i < Q; i++) {
		cin >> n;
		if (n == 1) {	// p에 x를 추가
			cin >> p >> x;
			add(p, x);
		}
		else {	// p부터 q까지의 sum
			cin >> p >> q;
			cout << lgSum(p, q) << "\n";
		}
	}

	return 0;
}