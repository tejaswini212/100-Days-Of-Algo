#include<bits/stdc++.h>
using namespace std;

// Function to store Next larger elements

vector <long long> nextLargerElement(long long arr[], int n){
    stack<long long> s;
    vector<long long> v;
    v.push_back(-1);
    s.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while((s.empty()==false) && (s.top()<=arr[i])){
            s.pop();
        }
        long long nextGreater = (s.empty())?(-1):(s.top());
        s.push(arr[i]);
        v.push_back(nextGreater);
    }
    reverse(v.begin(),v.end());
    return v;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
