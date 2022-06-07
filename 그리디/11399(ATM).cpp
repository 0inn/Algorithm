#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
vector<int> P;

int main() {
    cin >> N;
    for (int i = 0, p; i < N; i++) {
        cin >> p;
        P.push_back(p);
    }
    sort(P.begin(), P.end());
    
    ans = P[0];
    for (int i = 1; i < N; i++) {
        P[i] += P[i-1];
        ans += P[i];
    }
    
    cout << ans;
    
    return 0;
}
