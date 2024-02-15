#include<bits/stdc++.h>
using namespace std;

void customSwap(int * arr, int i, int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void DNF(int arrToSort [], int size)
{
	int j=-1, i=0;
	while(i<size)
	{
		if(arrToSort[i]==0)
		{
			customSwap(arrToSort, i, j+1);
			j++;
		}
		i++;
	}
	j=size, i=size-1;
	while(i>=0)
	{
		if(arrToSort[i]==2)
		{
			customSwap(arrToSort, i, j-1);
			j--;
		}
		i--;
	}
}

int main(){
    int arr[] = {2,1,0,2,2,1,0};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    DNF(arr, n);  
    cout << "Sorted array: \n";  
    for (int i = 0; i < n; i++)  
        cout << arr[i] << " "; 
    cout<<"\n";
    return 0;
}
