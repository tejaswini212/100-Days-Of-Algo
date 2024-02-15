#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=6;
    vector<int> nums = {3,20,4,6,7,30};
    vector<int> msis(n,0);
    msis[0]=nums[0];
    int res = msis[0];
    for(int i=1;i<n;i++){
        msis[i]=nums[i];
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i])
                msis[i] = max(msis[i],msis[j]+nums[i]);
        }
        res = max(res,msis[i]);
    }
    cout<<res;
    return 0;
}