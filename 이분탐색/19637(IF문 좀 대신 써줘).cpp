#include <iostream>
#include <vector>
using namespace std;

struct info {
    string str;
    int num;
};

int N, M;
int low, high, mid;
string str;
vector<info> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0, num; i < N; i++) {
        cin >> str >> num;
        v.push_back({str, num});
    }
    for (int i = 0, x; i < M; i++) {
        cin >> x;
        low = 0;
        high = N - 1;
        while(low <= high) {
            mid = (low + high) / 2;
            if (x <= v[mid].num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (x > v[mid].num) {
            mid++;
        }
        cout << v[mid].str << "\n";
    }
}
