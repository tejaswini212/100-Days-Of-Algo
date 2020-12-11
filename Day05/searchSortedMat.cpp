#include<bits/stdc++.h> 
using namespace std;

//Fuction to search element in a row-wise and column-wise sorted matrix
bool search(vector<vector<int> > mat, int n, int m, int x) 
{
    if (n == 0) 
        return false; 
    
    int smallest = mat[0][0], largest = mat[n - 1][m - 1]; 
    if (x < smallest || x > largest) 
        return false; 
    
    // setting index for top right element 
    int i = 0, j = m - 1;  
    while (i < n && j >= 0)  
    { 
        if (mat[i][j] == x)  
            return true; 
        if (mat[i][j] > x) 
            j--; 
        else 
            i++; 
    } 
  
    //Element not found
    return false; 
}

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {

 	int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;

        if (search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 

