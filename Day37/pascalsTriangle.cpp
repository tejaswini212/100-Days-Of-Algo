class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> pascals;
        if(n==0)
            return pascals;
        vector<int> firstRow = {1};
        pascals.push_back(firstRow);
        if(n==1){
            return pascals;
        }
        for(int i=1;i<n;i++){
            vector<int> prev_row=pascals.back();
            vector<int> nums;
            nums.push_back({1});
            for(int j=1;j<i;j++)
                nums.push_back(prev_row[j-1]+prev_row[j]);
            nums.push_back({1});
            pascals.push_back(nums);
        }
        return pascals;
    }
};