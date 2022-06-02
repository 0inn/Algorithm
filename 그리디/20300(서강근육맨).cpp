#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;   // 10^18이기 때문에 long long으로 선언 (int는 10^9까지)

using namespace std;

int N, tmp;
ll t, ans, day;
vector<ll> health;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        health.push_back(t);
    }
    sort(health.begin(), health.end());
    
    if (N % 2 == 0) tmp = N - 1;
    else tmp = N - 2;
    
    for (int i = 0; i < N / 2; i++) {
        day = health[i] + health[tmp];
        if ( ans < day ) ans = day;
        tmp--;
    }
    
    if (ans < health.back()) ans = health.back();
    cout << ans;
    
    return 0;
}
