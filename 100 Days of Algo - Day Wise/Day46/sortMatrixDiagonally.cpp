class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,vector<int>> um;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                um[j-i].push_back(mat[i][j]);
        }
        
        for(auto itr=um.begin();itr!=um.end();itr++)
            sort(itr->second.begin(),itr->second.end());
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                mat[i][j] = um[j-i].back();
                um[j-i].pop_back();
            }
        }
        return mat;
    }
};