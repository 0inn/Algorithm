//
//  단어 나누기.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 12/2/24.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    cin >> input;
    string ans = "}";
    
    for(int i=0; i<input.size()-2; i++) {
        for(int j=i+1; j<input.size()-1; j++) {
            string cur = input;
            
            reverse(cur.begin(), cur.begin()+i+1);
            reverse(cur.begin()+i+1, cur.begin()+j+1);
            reverse(cur.begin()+j+1, cur.end());
            
            ans = min(ans, cur);
        }
    }
    
    cout << ans;
    return 0;
}
