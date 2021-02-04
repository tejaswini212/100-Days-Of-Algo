class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        int res=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        if(mp[nums[i]+1])
            res = max(res,mp[nums[i]]+mp[nums[i]+1]);
        if(mp[nums[i]-1])
            res = max(res,mp[nums[i]]+mp[nums[i]-1]);
        }
        return res;
    }
};