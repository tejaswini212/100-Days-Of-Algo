#include<bits/stdc++.h>
using namespace std;

void permutation(vector<int>& nums, vector<vector<int>>& res, vector<int>& v, vector<bool>& visited)
{
	if (v.size() == nums.size())
	{
		res.push_back(v);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			v.push_back(nums[i]);
			permutation(nums, res, v, visited);
			visited[i] = false;
			v.pop_back();
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> v;
	vector<bool> visited(nums.size());
	permutation(nums, res, v, visited);
	return res;
}

int main() {
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> ans = permute(nums);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < 3; j++)
			cout << ans[i][j]<<" ";
		cout << "\n";
	}
	return 0;
}