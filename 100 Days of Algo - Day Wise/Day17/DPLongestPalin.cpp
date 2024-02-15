#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define SIZE 250
using namespace std;

string LPS(string str) {
    
    int n = str.length();
    
    bool table[SIZE][SIZE];
    memset(table, 0, sizeof(table));

    int maxLength = 1;
    
    for (int i = 0; i < n; i++)
        table[i][i] = true;

    int start = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            if (table[i + 1][j - 1] == true && str[i] == str[j]) {
                table[i][j] = true;
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    string out = str.substr(start, maxLength);
    return out;
}

int main() {
    string res;
    res = LPS("abcddcba"); cout << res<<"\n";
    res = LPS("abcdedcba"); cout << res<<"\n";
    res = LPS("abcdedcbe"); cout << res << "\n";
    res = LPS("abcdefg"); cout << res << "\n";
    return 0;
}