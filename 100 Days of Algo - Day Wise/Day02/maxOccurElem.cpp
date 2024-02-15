//Maximum occurring integer for given ranges

#include <bits/stdc++.h>
using namespace std;

// L and R are input array
// maxx : maximum in R[]
// n: size of array
// arr[] : declared globally with size equal to maximum in L[] and R[]

int maxOccured(int L[], int R[], int n, int maxx){

    vector<int> prefSum;
    for(int i=0;i<=maxx+1;i++)
        prefSum.push_back(0);
    for(int i=0;i<n;i++){
        prefSum[L[i]]++;
        prefSum[R[i]+1]--;
    }
    int curr_max=prefSum[0],res=0;
    for(int i=1;i<=maxx+1;i++){
        prefSum[i]+=prefSum[i-1];
        if(curr_max<prefSum[i]){
            curr_max=prefSum[i];
            res=i;
        }
    }
    return res;
}

int main() {
	
	int t;
	
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n;
	    
	    //taking size of array
	    cin >> n;
	    int L[n];
	    int R[n];
	    
	    //adding elements to array L
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    
	    //adding elements to array R
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    
	    //calling maxOccured() function
	    cout << maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}