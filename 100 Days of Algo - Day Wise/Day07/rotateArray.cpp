#include<bits/stdc++.h>
using namespace std;

void rotateArr(int arr[], int d, int n){
    int low=0;
    int high=d-1;
    while(low<high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
    low=d;
    high=n-1;
    while(low<high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
    low=0;
    high=n-1;
    while(low<high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    //calling rotateArr() function
	    rotateArr(arr,d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
} 