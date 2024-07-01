//
//  단축키 지정.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 7/1/24.
//

#include <iostream>
#include <string>

using namespace std;

int N;
bool keys[27] = {false,};
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin.ignore();
    
    for(int i=0; i<N; i++) {
        getline(cin, str);
        
        int cur;
        char alpha = '\0';
        bool isAns = false;
        int idx = -1;
        for(int i=0; i<str.size(); i++) {
            char upper = toupper(str[i]);
            cur = (int)(upper-'A');
            
            if(keys[cur] || str[i] == ' ') continue;
            if(str[i-1] == ' '|| i == 0) {
                idx = i;
                alpha = upper;
                break;
            }
            else if (!isAns){
                isAns = true;
                idx = i;
                alpha = upper;
            }
        }
        if(idx!= -1) keys[(int)(alpha-'A')] = true;
        
        string ans;
        for(int i=0; i<str.size(); i++) {
            if(i==idx) ans = ans + '[' + str[i] + ']';
            else ans += str[i];
        }
        
        cout << ans << "\n";
    }
}
