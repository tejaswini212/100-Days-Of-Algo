class Solution {
public:
    int maximumScore(vector<int>& nums, int pos) {
        int n=nums.size();
        int ans=0;
        for(int i=nums[pos],left=pos,right=pos;i>=1;--i){
            while(left>0 && nums[left-1]>=i)
                left--;
            while(right+1<n && nums[right+1]>=i)
                right++;
            ans = max(ans,(right-left+1)*i);
        }
        return ans;
    }
};