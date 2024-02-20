class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, s = 0, e = height.size()-1;

        while(s <= e) {
            int cur = min(height[s], height[e]) * (e - s);
            ans = max(ans, cur);

            if(height[s] < height[e]) s++;
            else e--;
        }

        return ans;
    }
};