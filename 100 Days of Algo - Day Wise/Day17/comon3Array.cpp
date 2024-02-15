#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:    
   vector <int> commonElements (vector<int> &A1, vector<int>& A2, vector<int>& A3, int n1, int n2, int n3)
     {
       vector<int>res;
       int i = 0, j = 0, k = 0;
       while (i < n1 && j < n2 && k < n3) {
        if (A1[i] == A2[j] && A2[j] == A3[k]) {
            if(res.size()==0)
                res.push_back(A1[i]);
            else if(res.back()!=A1[i])
                res.push_back(A1[i]);
            i++;j++;k++;
        }
        else if (A1[i] < A2[j])
           i++;
        else if (A2[j] < A3[k])
          j++;
        else
          k++;
      }
   return res;
   }
};

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        vector<int>A1(n1,0);
        vector<int>A2(n2,0);
        vector<int>A3(n3);
        
        for (int i = 0; i < n1; i++) cin >> A1[i];
        for (int i = 0; i < n2; i++) cin >> A2[i];
        for (int i = 0; i < n3; i++) cin >> A3[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A1, A2, A3, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
} 