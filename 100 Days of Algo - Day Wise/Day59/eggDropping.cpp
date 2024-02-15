#include <iostream>
#include <limits.h>
using namespace std;

int res(int eggs, int floors) 
{ 
   
    int dp[eggs + 1][floors + 1]; 
    int res; 
   
  
   
    for (int i = 1; i <= eggs; i++) { 
        dp[i][1] = 1; 
        dp[i][0] = 0; 
    } 
  
   
    for (int j = 1; j <= floors; j++) 
        dp[1][j] = j; 
  
    
    for (int i = 2; i <= eggs; i++) { 
        for (int j = 2; j <= floors; j++) { 
            dp[i][j] = INT_MAX; 
            for (int x = 1; x <= j; x++) { 
                res = 1 + max( 
                              dp[i - 1][x - 1], 
                              dp[i][j - x]); 
                if (res < dp[i][j]) 
                    dp[i][j] = res; 
            } 
        } 
    } 
  
    
    return dp[eggs][floors]; 
} 


int main() {
    
    	int eggs = 2;

		int floors = 10;
    	cout<<res(eggs, floors);
    	
    	return 0;
}