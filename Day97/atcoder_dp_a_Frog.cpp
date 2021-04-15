#include<bits/stdc++.h>
using namespace std;
 
void solve(vector<int>& nums){
  vector<int> dp(nums.size(),0);
  dp[0]=0;
  dp[1]=abs(nums[1]-nums[0]);
  for(int i=2;i<nums.size();i++){
  	 int num1=dp[i-1]+abs(nums[i]-nums[i-1]);
     int num2=dp[i-2]+abs(nums[i]-nums[i-2]);
     dp[i]=min(num1,num2);
  }
  cout<<dp[nums.size()-1];
}
 
int main(){
  int N;
  cin>>N;
  vector<int> nums(N,0);
  for(int i=0;i<N;i++){
  	int p;
    cin>>p;
    nums[i]=p;
  }
  solve(nums);
  return 0;
}