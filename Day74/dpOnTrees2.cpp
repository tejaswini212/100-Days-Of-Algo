#include <iostream>
#include<vector>
#define MAX_NODES 100
using namespace std;

int in[MAX_NODES];
int out[MAX_NODES];

void dfs_in(vector<int> v[], int u, int parent)
{
    // initially every node has 0 height
    in[u] = 0;

    // traverse in the subtree of u
    for (int child : v[u]) {

        if (child == parent)
            continue;

        dfs_in(v, child, u);
        in[u] = max(in[u], 1 + in[child]);
    }
}

void dfs_out(vector<int> v[], int u, int parent)
{
    int mx1 = -1, mx2 = -1;

    // traverse in the subtress of u
    for (int child : v[u]) {
        if (child == parent)
            continue;
        if (in[child] >= mx1) {
            mx2 = mx1;
            mx1 = in[child];
        }

        else if (in[child] > mx2)
            mx2 = in[child];
    }

    // traverse in the subtree of u
    for (int child : v[u]) {
        if (child == parent)
            continue;

        int longest = mx1;

        if (mx1 == in[child])
            longest = mx2;

        out[child] = 1 + max(out[u], 1 + longest);

        dfs_out(v, child, u);
    }
}

void printHeights(vector<int> v[], int n)
{
    dfs_in(v, 1, 0);
    dfs_out(v, 1, 0);

    // print all maximum heights
    for (int i = 1; i <= n; i++)
        cout << "Max height for node "<< i << "  as root"<< " is " << max(in[i], out[i])<< "\n";
}

int main()
{
    int n = 11;
    vector<int> v[12];

    // initialize the tree given in the diagram
    v[1].push_back(2), v[2].push_back(1);
    v[1].push_back(3), v[3].push_back(1);
    v[1].push_back(4), v[4].push_back(1);
    v[2].push_back(5), v[5].push_back(2);
    v[2].push_back(6), v[6].push_back(2);
    v[3].push_back(7), v[7].push_back(3);
    v[7].push_back(10), v[10].push_back(7);
    v[7].push_back(11), v[11].push_back(7);
    v[4].push_back(8), v[8].push_back(4);
    v[4].push_back(9), v[9].push_back(4);
    printHeights(v, n);

    return 0;
}