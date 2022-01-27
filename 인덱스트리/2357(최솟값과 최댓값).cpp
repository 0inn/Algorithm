#include<bits/stdc++.h>
#define MAX 100001
#define INF 1000000001
using namespace std;
typedef long long ll;

int N, M, B;
ll IDT_min[MAX * 4];
ll IDT_max[MAX * 4];

void initIDT() {
	for (int i = B - 1; i > 0; i--) {	// 부모트리 생성하기
		IDT_min[i] = min(IDT_min[i * 2], IDT_min[(i * 2) + 1]);
	}
	for (int i = B - 1; i > 0; i--) {
		IDT_max[i] = max(IDT_max[i * 2], IDT_max[(i * 2) + 1]);
	}
}

ll lgMin(int l, int r) {	// l ~ r 중 최솟값
	l += (B - 1);
	r += (B - 1);
	ll Min = INF;
	while (l <= r) {
		if ((l % 2) == 1) Min = min(Min, IDT_min[l]);
		if ((r % 2) == 0) Min = min(Min, IDT_min[r]);

		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return Min;
}

ll lgMax(int l, int r) {	// l ~ r 중 최솟값
	l += (B - 1);
	r += (B - 1);
	ll Max = 0;
	while (l <= r) {
		if ((l % 2) == 1) Max = max(Max, IDT_max[l]);
		if ((r % 2) == 0) Max = max(Max, IDT_max[r]);

		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return Max;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (B = 1; B < N; B *= 2);	// 첫번째 왼쪽 index 구하기
	for (int i = B, n; i < N + B; i++) {
		cin >> IDT_min[i];
		IDT_max[i] = IDT_min[i];
	}
	initIDT();

	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;	// a ~ b번째 사이 최솟값, 최댓값
		cout << lgMin(a, b) << " " << lgMax(a, b) << "\n";
	}

	return 0;
}