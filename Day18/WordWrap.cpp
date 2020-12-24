#include<iostream>
using namespace std;
#define n 4
#define INF INT_MAX

int printSolution(int p[], int num);

void wordWrap(int l[], int M) {
    int extra[n + 1][n + 1];  //cost of extra space
    int lc[n + 1][n + 1];     //cost that line with words from i to j
    int c[n + 1]; //total cost of optimal arrangement
    int p[n + 1]; //for printing solution
    int i, j;

    // calculates extra space in a single line for words from i to j
    for (i = 1; i <= n; i++) {
        extra[i][i] = M - l[i - 1];
        for (j = i + 1; j <= n; j++)
            extra[i][j] = extra[i][j - 1] - l[j - 1] - 1;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (extra[i][j] < 0)
                lc[i][j] = INF;
            else if (j == n && extra[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = extra[i][j] * extra[i][j];
        }
    }

    c[0] = 0;
    for (j = 1; j <= n; j++) {
        c[j] = INF;
        for (i = 1; i <= j; i++) {
            if (c[i - 1] != INF && lc[i][j] != INF && c[i - 1] + lc[i][j] < c[j]) {
                c[j] = c[i - 1] + lc[i][j];
                p[j] = i;
            }
        }
    }
    printSolution(p,n);
}

int printSolution(int p[], int num) {
    int k;
    if (p[num] == 1)
        k = 1;
    else
        k = printSolution(p, p[num] - 1) + 1;
    cout << "Line number " << k << " :From word number " << p[num] << " to " << num << "\n";
    return k;
}

int main() {
    int l[] = { 3,2,2,5 };
    int M = 6;
    wordWrap(l, M);
    return 0;
}