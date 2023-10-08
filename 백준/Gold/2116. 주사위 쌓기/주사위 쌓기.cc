//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/10/08.
//

#include <iostream>
#include <vector>
#include <map>
#define MAX 10001

using namespace std;

int N, ans;
vector<int> dices[MAX];
map<int, int> dice;
map<int, vector<int>> dice_pair;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0, num; j<6; j++) {
            cin >> num;
            dices[i].push_back(num);
        }
    }
}

void set_pair() {
    dice[0] = 5;
    dice[1] = 3;
    dice[2] = 4;
    dice[3] = 1;
    dice[4] = 2;
    dice[5] = 0;
    
    dice_pair[0] = {1, 2, 3, 4};
    dice_pair[1] = {0, 2, 4, 5};
    dice_pair[2] = {0, 1, 3, 5};
    dice_pair[3] = dice_pair[1];
    dice_pair[4] = dice_pair[2];
    dice_pair[5] = dice_pair[0];
}

int get_max(int idx, int cur) {
    int result = 0;
    
    for(int i=0; i<dice_pair[cur].size(); i++) {
        int nxt_idx = dice_pair[cur][i];
        result = max(result, dices[idx][nxt_idx]);
    }
    
    return result;
}

int cal_dice_max(int n) {
    int num = dices[0][n];
    int result = get_max(0, n);
    
    for(int i=1; i<N; i++) {
        for(int j=0; j<6; j++) {
            if(dices[i][j] == num) {
                num = dices[i][dice[j]];
                result += get_max(i, j);
                break;
            }
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    set_pair();
    for(int i=0; i<6; i++) {
        ans = max(ans, cal_dice_max(i));
    }
    
    cout << ans;
}
