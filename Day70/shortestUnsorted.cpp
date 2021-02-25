class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> n1 = nums;
        sort(n1.begin(),n1.end());
        int res=nums.size();
        int left=0;
        int right=res-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1[i])
                left++;
            else
                break;
        }
        for(int j=nums.size()-1;j>=0;j--){
            if(nums[j]==n1[right])
                right--;
            else
                break;
        }
        if(left==right || left==res)
            return 0;
        res=right-left+1;
        return res;
    }
};