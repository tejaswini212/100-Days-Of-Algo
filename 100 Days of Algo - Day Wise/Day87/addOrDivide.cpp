#include<iostream>
#include<vector>

using namespace std;

long long findmin(long long A,long long B){
	if (A == 0)
		return 0;
	long long res, a, b, i, ans;
	res = A + 3;
	if (B == 1)
		i = 1;
	else
		i = 0;
	for (;i < res;i++) {
		ans = i;
		a = A;
		b = B+i;
		while (a) {
			a = a / b;
			ans++;
		}
		if (ans < res)
			res = ans;
	}
	return res;
}

void solve(int t) {
	while (t--) {
		long long a, b;
		cin >> a >> b;
		long long res = findmin(a, b);
		cout << res << "\n";
	}
}

int main() {
	int t;
	cin >> t;
	solve(t);
	return 0;
}