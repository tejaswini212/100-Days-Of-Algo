#include<bits/stdc++.h>
using namespace std;

int editDist(string s1,string s2,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    for(int j=1;j<=n;j++)
        dp[0][j]=j;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i]==s2[j])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    return dp[m][n];
}

int main(){
    string s1="saturday";
    string s2="sunday";
    int m=s1.size();
    int n=s2.size();
    int res = editDist(s1,s2,m,n);
    cout<<res;
    return 0;
}