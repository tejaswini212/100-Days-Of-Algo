class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int>res1;
        if(matrix.empty()) return res1;
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0,j=0;
        vector<int> res;
        bool isUp = true;
        for(int k=0;k<m*n;){
            if(isUp){
                for(;i>=0 && j<n;j++,i--){
                    res.push_back(matrix[i][j]);
                    k++;
                }
                if(i<0 && j<=n-1)
                    i=0;
                if(j==n){
                    i+=2;
                    j--;
                }
            }
            else{
                for(;j>=0 && i<m;i++,j--){
                    res.push_back(matrix[i][j]);
                    k++;
                }
                if(j<0 && i<=m-1)
                    j=0;
                if(i==m){
                    j+=2;
                    i--;
                }                    
            }
            isUp = !isUp;
        }
        return res;
    }
};