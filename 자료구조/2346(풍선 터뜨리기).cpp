#include <iostream>
#include <vector>
using namespace std;

struct info {
    int idx, nxt;
};

int n;
vector <info> v;

int main() {
    cin >> n;
    for (int i = 1, num; i <= n; i++) {
        cin >> num;
        v.push_back({i, num});
    }
    
    while(!v.empty()) {
        cout << v.front().idx << " ";
        int nxt = v.front().nxt;
        v.erase(v.begin());
        if (nxt > 0) {  // 오른쪽 이동
            for (int i = 0; i < nxt - 1; i++) {
                v.push_back(v.front());
                v.erase(v.begin());
            }
        } else {  // 왼쪽 이동
            for (int i = 0; i < (nxt * (-1)); i++) {
                v.insert(v.begin(), v.back());
                v.erase(v.end() - 1);
            }
        }
    }
    
    return 0;
}
