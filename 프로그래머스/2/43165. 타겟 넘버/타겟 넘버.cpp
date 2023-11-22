#include <vector>

using namespace std;

int ans = 0;

void dfs(vector<int> nums, int k, int cnt, int sum) {
    if(cnt == nums.size()) {
        if(sum == k) ans++;
        return;
    }
    dfs(nums, k, cnt + 1, sum + nums[cnt]);
    dfs(nums, k, cnt + 1, sum - nums[cnt]);
}

int solution(vector<int> numbers, int target) {    
    dfs(numbers, target, 0, 0);
    
    return ans;
}