class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        int n=edges.size();
        for(int i=0;i<n;i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        for(auto it:mp){
            if(it.second==n){
                int ct=0;
                for(int i=0;i<n;i++){
                    if(edges[i][0]==it.first || edges[i][1]==it.first)
                        ct++;
                }
                if(ct==n)
                    return it.first;
            }
        }
        return -1;
    }
};