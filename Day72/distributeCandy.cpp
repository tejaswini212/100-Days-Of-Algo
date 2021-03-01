class Solution {
public:
    int distributeCandies(vector<int>& cT) {
        map<int,int> mp;
        int n=cT.size();
        for(int i=0;i<n;i++)
            mp[cT[i]]++;
        int k = n/2;
        int count=0;
        for(auto x:mp){
            if(k!=0){
                count++;
                k--;
            }
        }
        return count;
    }
};