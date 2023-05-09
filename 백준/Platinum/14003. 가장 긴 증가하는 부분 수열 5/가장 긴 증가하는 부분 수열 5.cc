//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/05/09.
//

#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int n, idx;
int arr[MAX], lis[MAX], idx_arr[MAX], ans[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    int a;
    for(int i=1; i<=n; i++) {
        cin >> a;
        arr[i] = a;
        
        if(idx == 0) {
            lis[idx++] = a;
            idx_arr[i] = 0;
        }
        else {
            if(lis[idx-1] < a) {
                idx_arr[i] = idx;
                lis[idx++] = a;
            }
            else {
                idx_arr[i] = lower_bound(lis, lis+idx, a) - lis;
                lis[idx_arr[i]] = a;
            }
        }
    }
    
    cout << idx << "\n";
    
    int ans_idx = 0;
    for(int i=n; i>=1; i--) {
        if(idx == idx_arr[i] + 1) {
            ans[ans_idx++] = arr[i];
            idx--;
        }
    }
    
    for(int i=ans_idx-1; i>=0; i--) cout << ans[i] << " ";
}
