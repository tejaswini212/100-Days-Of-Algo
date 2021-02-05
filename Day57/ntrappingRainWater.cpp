int trappingWater(int arr[], int n){
    int res=0;
    int lMax[n];
    int rMax[n];
    lMax[0]=arr[0];
    rMax[n-1]=arr[n-1];
    for(int i=1;i<n;i++)
        lMax[i]=max(lMax[i-1],arr[i]);
    for(int j=n-2;j>=0;j--)
        rMax[j]=max(rMax[j+1],arr[j]);
    for(int i=1;i<n-1;i++)
        res = res + (min(lMax[i],rMax[i]))-arr[i];
    return res;
}