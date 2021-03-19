class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int prevdiff=nums[1]-nums[0];
        int count=prevdiff!=0?2:1;
        for(int i=2;i<nums.size();i++){
            int diff=nums[i]-nums[i-1];
            if(prevdiff>=0 && diff<0){
                prevdiff=nums[i]-nums[i-1];
                count++;
            }else if(prevdiff<=0 && diff>0){
                prevdiff=nums[i]-nums[i-1];
                count++;
            }
        }        
        return count;
    }
};