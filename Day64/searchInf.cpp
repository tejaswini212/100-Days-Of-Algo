#include<iostream>
#include<vector>
using namespace std;

int binSearch(vector<int>& nums,int x,int low,int high) {
	while (low <= high) {
		int mid = low + (high-low) / 2;
		if (nums[mid] == x)
			return mid;
		if (nums[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int search(vector<int>& nums,int x) {
	if (nums[0] == x)
		return 0;
	int i = 1;
	while (nums[i] < x)
		i = i * 2;
	if (nums[i] == x)
		return i;
	return binSearch(nums, x, i / 2 + 1, i - 1);
}

int main() {
	vector<int> nums = {15,20,500,600,700,800,900,1000,1,10,12};
	int x = 12;
	int res= search(nums,x);
	cout << res;
	return 0;
}