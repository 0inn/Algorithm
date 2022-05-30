#include <iostream>
#include <cmath>
#define MAX 1025
using namespace std;

int k, input, root, cnt;
int arr[MAX];
bool check[MAX];

int main() {
    cin >> k;
    input = pow(2, k);
    root = input / 2;
    for (int i = 1; i < input; i++) {
        cin >> arr[i];
    }
    cout << arr[root] << "\n";
    check[root] = true;
    
    while(true) {
        if (cnt == (k - 1)) break;
        root /= 2;
        for (int i = root; i < input; i+= root) {
            if (check[i]) continue;
            cout << arr[i] << " ";
            check[i] = true;
        }
        cout << "\n";
        cnt++;
    }
    
    return 0;
}
