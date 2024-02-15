#include<bits/stdc++.h>
using namespace std;
 
void solve(vector<int>& nums,int K){
  vector<int> dp(nums.size(),1000000009);
  dp[0]=0;
  for(int i=1;i<nums.size() && i<=K;i++){
  	dp[i] = min(dp[i],abs(nums[i]-nums[0]));
  }
  for(int i=K+1;i<nums.size();i++){
  	 for(int j=1;j<=K;j++){
     	dp[i]=min(dp[i],dp[i-j]+abs(nums[i]-nums[i-j]));
     }
  }
  cout<<dp[nums.size()-1];
}
 
int main(){
  int N,K;
  cin>>N>>K;
  vector<int> nums(N,0);
  for(int i=0;i<N;i++){
  	int p;
    cin>>p;
    nums[i]=p;
  }
  solve(nums,K);
  return 0;
}