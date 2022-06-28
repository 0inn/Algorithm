#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int N, M;
ll low, high, H, ans;
vector<ll> t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0, tree; i < N; i++) {
        cin >> tree;
        t.push_back(tree);
    }
    sort(t.begin(), t.end());
    
    high = t[t.size()-1];
    while(low <= high) {
        ll mid = (low + high) / 2;
        H = 0;
        for (int i = 0; i < N; i++) {
            if (t[i] - mid > 0) {
                H += t[i] - mid;
            }
        }
        if (H >= M) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans;
}
