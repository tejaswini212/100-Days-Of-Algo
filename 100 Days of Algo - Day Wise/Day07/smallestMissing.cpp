#include<bits/stdc++.h>
using namespace std;

// Function to find first smallest positive missing number in the array
int missingNumber(int A[], int n) { 
    bool present[n+1]={false};
    for(int i=0;i<n;i++){
        if(A[i]>0 && A[i]<=n)
            present[A[i]]=true;
    }
    for(int i=1;i<=n;i++)
        if(!present[i])
            return i;
    return n+1;
} 

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        //calling missingNumber()
        cout<<missingNumber(arr, n)<<endl;
    }
    return 0; 
}