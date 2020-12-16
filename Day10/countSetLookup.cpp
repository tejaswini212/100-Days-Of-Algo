#include<bits/stdc++.h>
using namespace std;
int table[256];
void initialize(){
    table[0]=0;
    for(int i=1;i<256;i++)
        table[i] = (i&1) + table[i/2];
}

int main(){
    int n=128;
    initialize();
    int res=table[n&0xff];
    n = n>>8;
    //cout<<res;
    res = res + table[n&0xff];
    n = n>>8;
    res = res + table[n&0xff];
    n = n>>8;
    res = res + table[n&0xff];
    cout<<res<<"\n";
    return 0;
}
