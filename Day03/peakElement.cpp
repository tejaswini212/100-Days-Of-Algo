#include<bits/stdc++.h>
using namespace std;

//Fuction to return the index of peak element
// arr: input array
// n: size of array

int peakElement(int arr[], int n)
{
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if((arr[mid]>=arr[mid-1] || mid==0) && (mid==n-1 || arr[mid+1]<=arr[mid]))
            return mid;
        else if(mid>0 && arr[mid-1]>arr[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}

	return 0;
}