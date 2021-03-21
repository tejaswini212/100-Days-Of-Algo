#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;

int find(int n, set<int>& s) {
    while (true) {
        n++;
        int p = n;
        while (p) {
            int num = p % 10;
            if (s.find(num) != s.end())
                break;
            p = p / 10;
        }
        if (p == 0)
            return n;
    }
}

int main() {
    int n, k;
    set<int> s;
    cin >> n >> k;
    for (int i = 0;i < k;i++) {
        int p;
        cin >> p;
        s.insert(p);
    }
    cout << find(n - 1, s);
    return 0;
}