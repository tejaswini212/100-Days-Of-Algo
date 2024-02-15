#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> prices = { 12,11,13,9,12,8,14,13,15 };
	int maxTotalProfit = 0;
	vector<int> firstBuyAndSell(prices.size(), 0);
	int minPrice = INT_MAX;
	for (int i = 1; i < prices.size(); i++) {
		minPrice = min(minPrice, prices[i]);
		maxTotalProfit = max(maxTotalProfit, prices[i] - minPrice);
		firstBuyAndSell[i] = maxTotalProfit;
	}

	//Backward calculation for second buy and sell
	int maxPrice = INT_MIN;
	for (int i = prices.size() - 1; i > 0; i--) {
		maxPrice = max(maxPrice, prices[i]);
		maxTotalProfit = max(maxTotalProfit, maxPrice - prices[i] + firstBuyAndSell[i - 1]);
	}
	cout << maxTotalProfit;
	return 0;
}