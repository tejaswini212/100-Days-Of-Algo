#include<bits/stdc++.h>
using namespace std;

vector<int> PlusOne(vector<int>& A) {
	++A.back();
	for (int i = A.size() - 1; i > 0 && A[i]==10; i--) {
		A[i] = 0;
		A[i - 1]++;
	}
	if (A[0] == 10) {
		A[0] = 0;
		A.insert(A.begin(), 1);
	}
	return A;
}

int main() {
	vector<int> A = {9,9},B;
	A = PlusOne(A);
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	return 0;
}