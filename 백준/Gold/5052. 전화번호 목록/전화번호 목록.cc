//
//  main.cpp
//  Algorithm-c++
//
//  Created by 김영인 on 2023/12/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n;
string num;

string is_list(vector<string> nums) {
    bool is_list = true;
    
    for(int i=1; i<nums.size(); i++) {
        int cnt = 0;
        for(int j=0; j<nums[i-1].size(); j++) {
            if(nums[i][j] == nums[i-1][j]) cnt++;
        }
        if(cnt == nums[i-1].size()) is_list = false;
    }
    
    return is_list ? "YES" : "NO";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    while(t--) {
        cin >> n;
        vector<string> nums;
        while(n--) {
            cin >> num;
            nums.push_back(num);
        }
        sort(nums.begin(), nums.end());
        cout << is_list(nums) << "\n";
    }
}
