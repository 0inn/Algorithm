//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/12/02.
//

#include <iostream>
#include <string>
using namespace std;

struct answer {
    int first = 1, second = 1;
};

int x;

answer solve_ans() {
    answer ans;
    int idx = 1, cur_cnt = 1, cnt = 1;
    bool isDown = false;

    while(idx != x) {
        if(cur_cnt == cnt) {
            cnt = 1;
            if(!isDown) {
                ans.second += 1;
                isDown = true;
            } else {
                ans.first += 1;
                isDown = false;
            }
            idx++;
            cur_cnt++;
            continue;
        }
        
        if(isDown) {
            ans.first++;
            ans.second--;
        } else {
            ans.first--;
            ans.second++;
        }
        
        idx++;
        cnt++;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> x;
    answer ans = solve_ans();
    cout << ans.first << "/" << ans.second;
}
