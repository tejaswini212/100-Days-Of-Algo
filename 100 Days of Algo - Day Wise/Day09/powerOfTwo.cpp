#include<bits/stdc++.h>
using namespace std;

// Function to check power of two
bool isPowerofTwo(long long n){

    int count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    if(count==1) return true;
    return false;
}

int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;
        if(n<=0) // if n is less than equal to zero then it can't be a power of 2
        {
            cout<<"NO"<<endl; 
            continue; 
        }

         if(isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;
    }
    return 0;
}