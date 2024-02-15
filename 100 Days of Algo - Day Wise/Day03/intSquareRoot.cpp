#include<bits/stdc++.h>
using namespace std;

// Function to find square root

long long int floorSqrt(long long int x) 
{
    long long int high=x,ans=-1;
    long long int low=1;
    while (low<=high){
        long long int mid=(low+high)/2;
        long long int msq=mid*mid;
        if(msq==x)
            return mid;
        else if(msq>x)
            high = mid-1;
        else
        {
            low=mid+1;
            ans=mid;
        }
    }
    return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;   
}