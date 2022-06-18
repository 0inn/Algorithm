#include <iostream>
using namespace std;

int N, M;
int switches[101];

void onOff (int x) {
    if (switches[x] == 0) { switches[x] = 1; }
    else {switches[x] = 0; }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> switches[i];
    }
    cin >> M;
    for (int i = 0, s, n; i < M; i++) {
        cin >> s >> n;
        onOff(n);
        if (s == 1) {   // 남학생
            for (int j = n+n; j <= N; j+=n) {
                onOff(j);
            }
        } else {    // 여학생
            int tmp = n - 1;
            for (int j = n + 1; j <= N; j++) {
                if (tmp >= 1 && switches[tmp] == switches[j]) {
                    onOff(j);
                    onOff(tmp);
                    tmp--;
                } else {
                    break;
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << switches[i] << " ";
        if (i >= 20 && i % 20 == 0) { cout << " \n"; }
    }
}
