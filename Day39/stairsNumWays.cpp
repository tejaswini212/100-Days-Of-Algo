#include<iostream>
#include<vector>
using namespace std;

int num_ways(int N) {
	vector<int> dp(N+1, 0);
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		vector<int> a = { 1,3,5 };
		for (int j = 0; j < a.size(); j++) {
			if (i - a[j] >= 0)
				sum += dp[i - a[j]];
		}
		dp[i] = sum;
	}
	return dp[N];
}

int main() {
	int num = num_ways(5);
	cout << num;
	return 0;
}