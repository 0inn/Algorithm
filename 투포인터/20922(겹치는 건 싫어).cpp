#include<iostream>
#include<algorithm>
using namespace std;

int N, K, start, ans;
int a[200001], cnt[200001];

int main() {
    
//    cin >> N >> K;
//    for (int i = 0; i < N; i++) {
//        cin >> a[i];
//        cnt[a[i]]++;
//        while (cnt[a[i]] > K) {
//            cnt[a[start++]]--;
//        }
//        ans = max(ans, i - start + 1);
//    }
//    cout << ans;

    cin >> N >> K;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    int left = 0;
    int right = 0;
    while (left <= right && right < N) {
        if (cnt[a[right]] < K) {
            cnt[a[right++]]++;
            ans = max(ans, right - left);
        } else if (cnt[a[right]] == K) {
            cnt[a[left++]]--;
        }
    }
    cout << ans;
    
    return 0;
}
