#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, ans;
vector<int> coins;

int main() {
    cin >> N >> K;
    for (int i = 0, A; i < N; i++) {
        cin >> A;
        coins.push_back(A);
    }
    sort(coins.begin(), coins.end(), greater<int>());
    
    for (int i = 0; i < coins.size(); i++) {
        int coinCnt = (K/coins[i]);
        if (coinCnt > 0) {
            K -= (coinCnt * coins[i]);
            ans += coinCnt;
        }
        if (K == 0) {
            cout << ans;
            return 0;
        }
    }
}
