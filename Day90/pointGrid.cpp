#include <iostream>
#include <vector>
using namespace std;

int findMin(int a,int b){
    if(a-b>=1)
        return b;
    else
        return min(a,b)-1;
}

void solve(int t){
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n,0);
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            int p;
            cin>>p;
            A[i]=p;
            sum+=p;
        }
        if(n==1){
            cout<<A[0]<<"\n";
        }
        else{
            for(int i=n-2;i>=0;i--){
                int num=findMin(A[i],A[i+1]);
                sum-=num;
            }
            cout<<sum<<"\n";
        }
    }
    return;
}

int main() {
	int t;
	cin>>t;
	solve(t);
	return 0;
}