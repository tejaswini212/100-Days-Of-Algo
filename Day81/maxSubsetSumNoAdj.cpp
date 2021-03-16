int maxSubsetSumNoAdjacent(vector<int> array) {
  if(array.size()==0)
		return 0;
	if(array.size()==1)
		return array[0];
	if(array.size()==2)
		return max(array[0],array[1]);
	vector<int> dp(array.size(),-1);
	dp[0]=array[0];
	dp[1]=max(array[0],array[1]);
	for(int i=2;i<array.size();i++){
		dp[i] = max(dp[i-2]+array[i],dp[i-1]);
	}
	return dp[array.size()-1];
}
