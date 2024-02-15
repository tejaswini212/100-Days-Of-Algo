#include<iostream>
using namespace std;

void solve(int t) {
    while (t--) {
        int n, w1, w2;
        cin >> n >> w1 >> w2;
        int w, b;
        cin >> w >> b;
        int b1 = n - w1;
        int b2 = n - w2;
        if ((w1 + w2) / 2 >= w && (b1 + b2) / 2 >= b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return;
}

int main() {
    int t;
    cin >> t;
    solve(t);
    return 0;
}