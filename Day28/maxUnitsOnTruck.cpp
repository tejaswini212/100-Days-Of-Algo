#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool sortcol(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] > v2[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), sortcol);
        int maxUnits = 0;
        int remBoxes = truckSize;
        for (int i = 0; i < boxTypes.size(); i++) {
            if (boxTypes[i][0] <= remBoxes) {
                maxUnits += boxTypes[i][0] * boxTypes[i][1];
                remBoxes = remBoxes - boxTypes[i][0];
            }
            else {
                if (remBoxes != 0) {
                    if (remBoxes < boxTypes[i][0]) {
                        maxUnits += remBoxes * boxTypes[i][1];
                        remBoxes = 0;
                        break;
                    }
                }
            }
        }
        return maxUnits;
    }
};

int main() {
    Solution s;
    vector<vector<int>> boxTypes = { {1, 3},{2, 2},{3, 1} };
    int truckSize = 4;
    int res = s.maximumUnits(boxTypes, truckSize);
    cout << res << "\n";
    return 0;
}