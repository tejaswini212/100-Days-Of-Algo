#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main() {
    vector<int> a = { 35,20,-11,-6,-4,10,30 };
    unordered_set<int> s;
    int prefSum = 0;
    int flag = 1;
    for (int i = 0; i < a.size(); i++) {
        prefSum += a[i];
        if (s.find(prefSum) != s.end())
        {
            flag = 0;
            cout << "YES";
            break;
        }
        if (prefSum == 0)
        {
            flag = 0;
            cout << "YES";
            break;
        }
        else
            s.insert(prefSum);
    }
    if(flag!=0)
        cout << "NO";
    return 0;
}