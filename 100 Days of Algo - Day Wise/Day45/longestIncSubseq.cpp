// return length of longest strictly increasing subsequence
int longestSubsequence(int n, int a[])
{
   // your code here
   int dp[n+1];
        int mx=-1;
        dp[0]=1;
        mx=1;
    for(int i=1;i<n;i++)
    { 
        dp[i]=1;
        for(int j=0;j<i;j++){
        if(a[i]>a[j])
        {
            dp[i]=max(dp[j]+1,dp[i]);
            mx=max(dp[i],mx);
        }
            
        }
    }
   return mx;
}
