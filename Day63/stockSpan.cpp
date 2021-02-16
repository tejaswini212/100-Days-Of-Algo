#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int>st;
	//int arr[10] = { 10,5,13,14,20,9,26,10,40,1 };
	//int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << 1 << " ";
	st.push(0);
	for (int i = 1; i < 10; i++) {
		while (!st.empty() && arr[st.top()] <= arr[i])
			st.pop();
		int span = st.empty() ? i + 1 : i - st.top();
		cout << span << " ";
		st.push(i);
	}
	return 0;
}