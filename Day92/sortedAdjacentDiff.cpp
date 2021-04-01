#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
void solve(int t){
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n,0);
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            nums[i]=p;
        }
        sort(nums.begin(),nums.end());
        while(nums.size())
        {
            cout<<nums[nums.size()/2]<<" ";
            nums.erase(nums.begin()+nums.size()/2);
        }
        cout<<"\n";
    }
    return;
}
 
int main(){
    int t;
    cin>>t;
    solve(t);
    return 0;
}