#include<bits/stdc++.h>
#define INF 1000000001
#define MAX 100001
using namespace std;
typedef long long ll;

int N, M, B;
ll IDT[MAX * 3];

void initIDT() {
	for (int i = B - 1; i > 0; i--) {
		IDT[i] = min(IDT[i * 2], IDT[i * 2 + 1]);
	}
}

int lgMin(int l, int r) {
	l += (B - 1);
	r += (B - 1);
	ll Min = INF;
	while (l <= r) {
		if ((l % 2) == 1) Min = min(Min, IDT[l]);
		if ((r % 2) == 0) Min = min(Min, IDT[r]);
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return Min;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (B = 1; B < N; B *= 2);
	for (int i = B; i < B + N; i++) {
		cin >> IDT[i];
	}
	initIDT();

	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		cout << lgMin(a, b) << "\n";
	}

	return 0;
}