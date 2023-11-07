//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/07.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
typedef long long ll;

using namespace std;

ll N, ans;
vector<int> students;

void input() {
    cin >> N;
    
    int num;
    while(N--) {
        cin >> num;
        students.push_back(num);
    }
}

void solution() {
    sort(students.begin(), students.end());
    
    int cur = 1;
    for(auto num: students) {
        ans += abs(num - cur);
        cur++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solution();
    cout << ans;
}
