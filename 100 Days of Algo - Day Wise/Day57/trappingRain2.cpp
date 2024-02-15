//O(n^2) approach
int trappingWater(int arr[], int n){

    // Your code here
    int res=0;
    for(int i=1;i<n-1;i++){
        int lMax=arr[i];
        int rMax=arr[i];
        for(int j=0;j<i;j++)
            lMax = max(lMax,arr[j]);
        for(int j=i+1;j<n;j++)
            rMax = max(rMax,arr[j]);
        res+=min(lMax,rMax)-arr[i];
    }
    return res;
}