#include<iostream>
#include<vector>
using namespace std;
int dp[100];

void dfs(int a[], vector<int> v[], int u, int parent) {
    dp[u] = a[u - 1];
    int max1 = 0;
    for (int child : v[u]) {
        if (child == parent)
            continue;
        dfs(a, v, child, u);
        max1 = max(max1, dp[child]);
    }
    dp[u] += max1;
}

int maximumValue(int a[], vector<int> v[])
{
    dfs(a, v, 1, 0);
    return dp[1];
}

int main() {
	int n = 14;
	vector<int> v[15];
    v[1].push_back(2), v[2].push_back(1);
    v[1].push_back(3), v[3].push_back(1);
    v[1].push_back(4), v[4].push_back(1);
    v[2].push_back(5), v[5].push_back(2);
    v[2].push_back(6), v[6].push_back(2);
    v[3].push_back(7), v[7].push_back(3);
    v[4].push_back(8), v[8].push_back(4);
    v[4].push_back(9), v[9].push_back(4);
    v[4].push_back(10), v[10].push_back(4);
    v[5].push_back(11), v[11].push_back(5);
    v[5].push_back(12), v[12].push_back(5);
    v[7].push_back(13), v[13].push_back(7);
    v[7].push_back(14), v[14].push_back(7);
    int a[] = {3,2,1,10,1,3,19,1,5,3,4,5,9,8};
    cout << maximumValue(a, v);
	return 0;
}