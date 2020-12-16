#include<bits/stdc++.h>
using namespace std;

int main(){
    int XOR=0;
    int arr[] = {3,4,3,4,5,4,4,6,7,7};
    for(auto x:arr)
        XOR ^= x;
    int n=10;
    int res1=0,res2=0;
    int sn = XOR & ~(XOR-1);
    for(int i=0;i<n;i++){
        if((arr[i] & sn)!=0)
            res1 = res1^arr[i];
        else
            res2 = res2^arr[i];
    }
    cout<<res1<<" "<<res2<<"\n";
    return 0;
}
