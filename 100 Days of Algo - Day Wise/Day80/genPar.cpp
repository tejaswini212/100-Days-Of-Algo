class Solution {
public:
    void getcombinations(vector<string> &par, string com,int left,int right,int n, int bal){
        if(left == n && right == n){
            par.push_back(com);
            return;
        }
        if(left < n){
            getcombinations(par,com+"(",left+1,right,n,bal+1);
        }
        if(right < n && bal>0){
            getcombinations(par,com+")",left,right+1,n,bal-1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> par;
        if(n==1){
            par.push_back("()");
            return par;
        }
        string com="";
        getcombinations(par,com,0,0,n,0);
        return par;
    }
};