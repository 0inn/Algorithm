#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

bool comp(int i, int j) {
    return i > j;
}

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end(), comp);
    
    int sum = 0, start = 0;
    
    for(int i=0; i<people.size(); i++) {
        sum = people[i] + people[people.size()-1];
        if(sum <= limit) {
            people.pop_back();
            start++;
        }
        ans++;
    }
    
    return ans;
}