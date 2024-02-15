class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        int j=1;
        int num=0;
        while(count!=k){
            int flag=0;
            for(int i=0;i<arr.size();i++){
                if(j==arr[i])
                    flag=1;
            }
            if(flag==0){
                num = j;
                count++;
            }
            j++;
        }
        return num;
    }
};