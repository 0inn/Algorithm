//
//  11723(집합).cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/04/29.
//

#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int M, x;
string cmd;
int s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> M;
    while (M--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            s |= (1<<x);
        } else if (cmd == "remove") {
            cin >> x;
            s &= ~(1<<x);
        } else if (cmd == "check") {
            cin >> x;
            if (s & (1<<x)) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (cmd == "toggle") {
            cin >> x;
            s ^= (1<<x);
        } else if (cmd == "all") {
            s = (1<<21) -1;
        } else if (cmd == "empty") {
            s = 0;
        }
    }
}
