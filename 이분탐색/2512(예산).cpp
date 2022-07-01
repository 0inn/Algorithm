#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int N, M;
ll low, high, sum, ans;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
    cin >> M;
    sort(v.begin(), v.end());
    high = v[v.size()-1];
    while (low <= high) {
        ll mid = (low + high) / 2;
        sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= mid) {
                sum += mid;
            } else {
                sum += v[i];
            }
        }
        if (sum <= M) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans;
}
