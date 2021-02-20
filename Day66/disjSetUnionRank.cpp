#include <iostream>
using namespace std;
#define n 5

int parent[n];
int rank[n];

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
    if(rank[x_rep]<rank[y_rep])
        parent[x_rep] = y_rep;
    else if(rank[y_rep]<rank[x_rep])
        parent[y_rep] = x_rep;
    else{
      rank[x_rep]++;
      parent[y_rep]=x_rep;
    }
}

int main() {
  for(int i=0; i<n; i++){
    parent[i]=i;
    rank[i]=0;
  }

  unions(3,4);
  unions(2,3);
  unions(1,2);
  unions(0,1);

  cout<<parent[3]<<"\n";
  cout<<ranks[3]<<"\n";

  return 0;
}
