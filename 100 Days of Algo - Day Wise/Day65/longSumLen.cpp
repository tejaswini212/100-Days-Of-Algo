#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    vector<int> a = { 8,3,1,5,1,2,2,3 };
    unordered_map<int,int> mp;
    int sum = 5;
    int prefSum = 0;
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        prefSum += a[i];
        if (prefSum == sum)
            res = i + 1;
        if (mp.find(prefSum-sum) != mp.end())
            res = max(res, i - mp[prefSum - sum]);
        if(mp.find(prefSum) == mp.end())
            mp.insert({prefSum, i});
    }
    cout << res << "\n";
    return 0;
}