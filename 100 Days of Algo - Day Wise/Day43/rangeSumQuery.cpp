#include<bits/stdc++.h>
using namespace std;

int rangeSum(int i, int j,int cache[]) {
	if (i == 0)
		return cache[j+1];
	return cache[j + 1] - cache[i];
}

int main() {
	vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };
	int n = nums.size();
	int cache[11];
	cache[0] = 0;
	for (int i = 0; i < n; i++)
		cache[i + 1] = cache[i] + nums[i];
	cout << rangeSum(7, 9, cache) <<"\n";
	cout << rangeSum(1, 3, cache) << "\n";
	cout << rangeSum(2, 8, cache) << "\n";
	return 0;
}