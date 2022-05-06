//
//  정수 삼각형.cpp
//  프로그래머스
//
//  Created by 김영인 on 2022/05/06.
//

#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for (int row = 1; row < triangle.size(); row++) {
        
        for (int i = 0; i < triangle[row].size(); i++) {
            
            int lastIdx = triangle[row].size() - 1;
            
            if (i == 0) {
                triangle[row][0] += triangle[row-1][0];
            }
            else if (i == lastIdx) {
                triangle[row][lastIdx] += triangle[row-1][lastIdx-1];
            }
            else {
                triangle[row][i] += max(triangle[row-1][i-1], triangle[row-1][i]);
            }
            
            answer = max(answer,triangle[row][i]);
        }
        
    }
    
    return answer;
}
