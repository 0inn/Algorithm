#include <iostream>
#include <algorithm>
using namespace std;

int N, d, num, cnt, ans;
int B[1001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    for (int i = 0; i < N; i++) {
        d = B[i];
        num = -1;
        cnt = 0;
        for (int j = 0; j < N; j++) {
            if (d == B[j]) { continue; }
            if (num == -1) {
                num = B[j];
                cnt++;
            } else if (num == B[j]) {
                cnt++;
            } else {
                num = B[j];
                cnt = 1;
            }
            ans = max(ans, cnt);
        }
    }
    
    cout << ans;
    
    return 0;
}
