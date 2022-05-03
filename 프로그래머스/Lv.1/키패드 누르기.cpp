//
//  키패드 누르기.cpp
//  BaekJoon
//
//  Created by 김영인 on 2022/05/03.
//

#include <bits/stdc++.h>
using namespace std;

struct info {
    int x, y;
};

/* 이 형태로 2차원 배열로 선언
    1 2 3
    4 5 6
    7 8 9
    * 0 #
*/

info arr[13] = {{4,2}, {1,1}, {1,2}, {1,3}, {2,1},
                {2,2}, {2,3}, {3,1}, {3,2}, {3,3}};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    info left = {4,1};  // *
    info right = {4,3}; // #
    
    for (int i = 0; i < numbers.size(); i++) {
        info num = arr[numbers[i]];
        switch (num.y) {
            case 1: // 왼쪽 열의 경우, L
                answer += "L";
                left = num;
                break;
            case 3: // 오른쪽 열의 경우, R
                answer += "R";
                right = num;
                break;
            default:
                int leftcomp = abs(left.x - num.x) + abs(left.y - num.y);
                int rightcomp = abs(right.x - num.x) + abs(right.y - num.y);
                // 거리 비교해서 더 가까운 쪽 손가락으로 입력
                if (leftcomp < rightcomp) {
                    answer += "L";
                    left = num;
                } else if (leftcomp > rightcomp) {
                    answer += "R";
                    right = num;
                } else {    // 같은 거리일 경우, 무슨 손잡이인지에 따라 다른 손 입력
                    if (hand == "left") {
                        answer += "L";
                        left = num;
                    } else {
                        answer += "R";
                        right = num;
                    }
                }
                break;
        }
    }
    
    return answer;
}
