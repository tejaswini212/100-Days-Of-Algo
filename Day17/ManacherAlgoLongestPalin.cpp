#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string LPS(string str) {
    
    int len = str.length();
    
    if (len < 2) return str;
    
    vector<char> T;
    T.push_back('$');
    T.push_back('#');
    
    int n = 2, C = 1, R = 1, maxlen = 0;

    for (int i = 0; i < len; i++) {
        T.push_back(str[i]);
        T.push_back('#');
        n += 2;
    }
    T.push_back('@');
    n++;
    vector<int>P(n, 0);
    //for (int i = 0; i < n; i++)
    //    P[i] = 0;

    //Manacher's Algorithm
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * C - i;
        if (i < R)
            P[i] = min(R - i, P[mirror]);
        while (T[i + (1 + P[i])] == T[i - (1 + P[i])])
            P[i]++;
        if (P[i] > maxlen)
            maxlen = P[i];
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int l;
    for (int i = 0; i < n; i++) {
        if (P[i] == maxlen) {
            if (i % 2 == 1)
                l = (i - 2) / 2 - (maxlen / 2 - 1);
            else
                l = (i - 2) / 2 - (maxlen / 2);
            break;
        }
    }
    string out = str.substr(l, maxlen);
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