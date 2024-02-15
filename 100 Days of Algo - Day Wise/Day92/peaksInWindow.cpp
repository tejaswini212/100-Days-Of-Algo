#include<iostream>
#include<vector>
using namespace std;
 
void solve(int t){
    while(t--){
        int n,k;   
        cin>>n>>k;
        vector<int> nums(n,0);
        vector<int> pref(n,0);
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            nums[i]=p;
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
                pref[i]=1;
        }
        for(int i=1;i<n;i++){
            pref[i]=pref[i]+pref[i-1];
        }
        int res=0;
        int currMax=0;
        for(int i=k-1;i<n;i++){
            int num=pref[i-1]-pref[i-k+1];
            if(num>currMax){
                res=i-k+1;
                currMax=num;
            }
        }
        cout<<currMax+1<<" "<<res+1<<"\n";
    }
}
 
int main(){
    int t;
    cin>>t;
    solve(t);
    return 0;
}