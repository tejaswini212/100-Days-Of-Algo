#include<iostream>
#include<string>
using namespace std;
 
int main() {
    string s, t="";
    int flag = 0;
    cin >> s;
    for (int i = 0;i < s.size();i++) {
        if (flag)
            break;
        if (s[i] == '.')
            break;
        else
            t += s[i];
    }
    cout << t;
    return 0;
}