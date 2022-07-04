/*
 lower_bound : key값이 없으면 key보다 큰 가장 작은 정수 값 찾음
 upper_bound : key값이 없으면 key값을 초과하는 가장 첫번째 원소의 위치 찾음
 ex.
 int arr[N];
 lower_bound(arr, arr+N, key)의 형태로 사용
 */

#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int N, M;
ll x, y;
ll arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        cout << upper_bound(arr, arr + N, y) - lower_bound(arr, arr + N, x) << "\n";
    }
}
