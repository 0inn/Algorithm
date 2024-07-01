//
//  스타트링크 타워.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 7/1/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

string numbers[5] = {
    "###...#.###.###.#.#.###.###.###.###.###",
    "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
    "#.#...#.###.###.###.###.###...#.###.###",
    "#.#...#.#.....#...#...#.#.#...#.#.#...#",
    "###...#.###.###...#.###.###...#.###.###"
};

int N;
string strs[5] = {"",};
vector<vector<int>> results;

void findNumbers(int cur, vector<int>& result) {
    for(int i=0; i<10; i++) {
        bool isNum = true;
        
        for(int r=0; r<5; r++) {
            for(int c=0; c<3; c++) {
                if(strs[r][c+(cur*4)] == '#' && numbers[r][c+(i*4)] == '.') {
                    isNum = false;
                    goto finish;
                }
            }
        }
    finish:
        if(isNum) result.push_back(i * pow(10, N-cur-1));
    }
}

ll total = 1;
double ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0; i<5; i++) {
        cin >> strs[i];
    }
    
    results.resize(N);
    for(int i=0; i<N; i++) {
        findNumbers(i, results[i]);
        total *= results[i].size();
    }
    
    if(total == 0) {
        cout << -1 << "\n";
        return 0;
    }
    
    ll tmp, sum = 0;
    for(int i=0; i<N; i++) {
        tmp = 0;
        for(auto num: results[i]) {
            tmp += num;
        }
        sum += tmp * (total/results[i].size());
    }
    
    ans = sum / (double)total;
    cout << ans;
}
