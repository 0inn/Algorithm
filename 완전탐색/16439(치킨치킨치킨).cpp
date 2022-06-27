#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cost, sum, ans;
int arr[31][31];
vector<bool> temp;
vector<int> chicken;

int main() {
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < M; i++) {
        if (i < M - 3) temp.push_back(false);
        else temp.push_back(true);
    }
    
    do {
        ans = max(ans, sum);
        chicken.clear();
        for (int i = 0; i < M; ++i) {
            if (temp[i]) {
                chicken.push_back(i);
            }
        }
        sum = 0;
        for (int i = 0; i < N; i++) {
            cost = 0;
            for (int j = 0; j < 3; j++) {
                cost = max(cost, arr[i][chicken[j]]);
            }
            sum += cost;
        }
    } while (next_permutation(temp.begin(), temp.end()));
    
    cout << ans;
}
