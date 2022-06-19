#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> D;
vector<int> S;
vector<int> P;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0, s; i < N; i++) {
        cin >> s;
        S.push_back(s);
        P.push_back(s);
    }
    for (int i = 0, d; i < N; i++) {
        cin >> d;
        D.push_back(d);
    }
    while(K--) {
        S = P;
        for (int i = 0; i < N; i++) {
            P[D[i] - 1] = S[i];
        }
    }
    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
}
