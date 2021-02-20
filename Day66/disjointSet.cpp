#include <iostream>
using namespace std;
#define n 5

int parent[n];

int find(int x){
    if(parent[x]==x)
        return x;
    else
        return find(parent[x]);
}

void unions(int x, int y){
    int x_rep = find(x);
    int y_rep = find(y);
    if(x_rep==y_rep)
        return;
    parent[y_rep]=x_rep;
}

int main() {
  for(int i=0; i<n; i++)
    parent[i]=i;

  unions(0,2);
  unions(0,4);

  cout<<find(4)<<"\n";
  cout<<find(0)<<"\n";
  cout<<find(3)<<"\n";

  return 0;
}
