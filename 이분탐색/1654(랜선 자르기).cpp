#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int K, N;
ll low, high, len, ans;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> K >> N;
    for (int i = 0, x; i < K; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    
    high = v[v.size()-1];
    while(low <= high) {
        ll mid = (low + high) / 2;
        if (mid == 0) { // 답이 1이 나올 수 있는 경우 고려
            mid = 1;
        }
        len = 0;
        for (int i = 0; i < K; i++) {
            len += v[i] / mid;
        }
        if (len >= N) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans;
}
