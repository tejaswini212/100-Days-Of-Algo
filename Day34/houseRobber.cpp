class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
          if (i >= 2) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
          } else if (i == 1) {
            dp[i] = max(nums[i], dp[i-1]);
          } else if (i == 0) {
            dp[i] = nums[i];
          }
        }
        return dp[n-1];
    }
};