#include<iostream>
using namespace std;
 
void solve(int t) {
	while (t--) {
		long long n, m, x;
		cin >> n >> m >> x;
		if (x > n * m)
			cout << -1 << "\n";
		else {
			long long num1 = (x % n == 0 ? 0 : 1);
			long long col = (x / n) + num1;
			long long row = x - (x / n) * n;
			if (row == 0)
				row = n;
			long long res = (row - 1) * m + col;
			cout << res << "\n";
		}
	}
}
 
int main() {
	int t;
	cin >> t;
	solve(t);
	return 0;
}