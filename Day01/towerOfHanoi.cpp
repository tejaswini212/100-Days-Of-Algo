//Tower of Hanoi Problem

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long toh(int N, int from, int to, int aux) {
        
        long long count=1;

	// Base case
        if(N==1){
            cout<<"move disk 1 from rod "<<from<<" to rod "<<to<<"\n";
            return count;
        }
        else{
            count+=toh(N-1,from,aux,to);
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<"\n";
            count+=toh(N-1,aux,to,from);
        }
        return count;
    }

};

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        long long moves = 0;
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        moves = ob.toh(N, 1, 3, 2);
        cout << moves <<"\n";
    }
    return 0;
}