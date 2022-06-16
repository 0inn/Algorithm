#include <iostream>
#include <algorithm>
using namespace std;

string S, str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    getline(cin, S);
    int nxt = 0;
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < S.size(); i++) {
        if ((S[i] == ' ' || i == S.size() - 1) && flag == false) {
            if ( i == S.size() - 1 ) {
                str = S.substr(nxt, cnt+1);
            } else {
                str = S.substr(nxt, cnt);
            }
            reverse(str.begin(), str.end());
            cout << str << ' ';
            nxt = i + 1;
            cnt = 0;
        }
        else if (S[i] == '<') {
            flag = true;
            if (cnt > 0) {
                str = S.substr(nxt, cnt);
                reverse(str.begin(), str.end());
                cout << str;
            }
            nxt = i;
            cnt = 0;
        } else if (S[i] == '>') {
            flag = false;
            cout << S.substr(nxt, cnt+2);
            nxt = i+1;
            cnt = 0;
        } else {
            cnt++;
        }
    }
    
}
