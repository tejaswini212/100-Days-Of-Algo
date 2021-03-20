class Solution {
public:
    int secondHighest(string s) {
        int flag=0;
        vector<int>num (10,0);
        for(int i=0;i<s.size();i++){
            if(s[i]>=48 && s[i]<=57){
                num[s[i]-48]++;
                flag=1;
            }
        }
        if(!flag)
            return -1;
        int flag1=0;
        int res=-1;
        // for(int i=0;i<10;i++)
        //     cout<<num[i];
        for(int i=9;i>=0;i--){
            if(flag1 && num[i])
                return i;
            if(!flag1 && num[i])
                flag1=1;
        }
        return res;
    }
};