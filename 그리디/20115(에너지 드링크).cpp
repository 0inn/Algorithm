#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
double ans;
vector<double> drink;

int main() {
    cin >> N;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        drink.push_back(x);
    }
    sort(drink.begin(), drink.end());
    ans = drink.back();
    
    for (int i = 0; i < N - 1; i++) {
        ans += (drink[i] / 2);
    }
    cout << ans;
    
    return 0;
}
