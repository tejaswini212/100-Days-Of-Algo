#include<bits/stdc++.h>
using namespace std;

// function to find position of first set bit in the given number
unsigned int getFirstSetBit(int n){
    int count=0;
    while(n){
        if(n&1){
            count++;
            break;
        }
        n=n>>1;
        count++;
    }
    return count;
}


int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        printf("%u\n", getFirstSetBit(n)); // function to get answer
    }
	return 0;
}