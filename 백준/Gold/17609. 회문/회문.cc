//
//  회전.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 9/16/24.
//

#include <iostream>
#include <string>
using namespace std;

int T;

int solution(string str) {
    int st = 0;
    int en = str.size()-1;
    bool fremoved = false;
    bool fisnot = false;
    
    while(st <= en) {
        if(str[st] != str[en]) {
            if(fremoved) {
                fisnot = true;
                break;
            } else {
                en--;
                fremoved = true;
                continue;
            }
        }
        st++;
        en--;
    }
    
    st = 0;
    en = str.size()-1;
    bool sremoved = false;
    bool sisnot = false;
    while(st <= en) {
        if(str[st] != str[en]) {
            if(sremoved) {
                sisnot = true;
                break;
            } else {
                st++;
                sremoved = true;
                continue;
            }
        }
        st++;
        en--;
    }
    
    if(!fremoved && !sremoved) return 0;
    else if(fisnot && sisnot) return 2;
    else return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    
    cin >> T;
    
    string str;
    while(T--) {
        cin >> str;
        cout << solution(str) << "\n";
    }
}
