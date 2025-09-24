class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dist(nums.size(), 10001);
        bool is_ans= false;

        dist[0] = 0;
        for (int i=0; i<nums.size(); i++) {
            int aval = nums[i];
            for (int j=1; j<=aval; j++) {
                if (i+j >= nums.size()) break;
                dist[i+j] = min(dist[i]+1, dist[i+j]);
                if (i+j == nums.size()-1) {
                   return dist[nums.size()-1];
                }
            }
        }

        return 0;
    }
};