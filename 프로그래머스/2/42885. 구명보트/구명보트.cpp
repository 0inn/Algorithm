#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    for(int i=people.size()-1, j=0; i>=j; i--) {
        if(people[i] + people[j] <= limit) {
            j++;
        }
        ans++;
    }
    
    return ans;
}