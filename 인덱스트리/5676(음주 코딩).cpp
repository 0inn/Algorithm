#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
typedef long long ll;

int N, B;
ll IDT[MAX * 4];

void initIDT() {
	for (int i = B - 1; i > 0; i--) {
		IDT[i] = IDT[i * 2] + IDT[i * 2 + 1];
	}
}

void update(int n, ll v) {
	n += (B - 1);
	IDT[n] = v;
	while (n /= 2) {
		IDT[n] = IDT[n * 2] + IDT[n * 2 + 1];
	}
}

ll lgSum(int l, int r) {
	l += (B - 1);
	r += (B - 1);
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
	cin.tie(0);

	cin >> N;
	for (B = 1; B < N; B *= 2);
	for (int i = B; i < N + B; i++) {

	}

	return 0;
}