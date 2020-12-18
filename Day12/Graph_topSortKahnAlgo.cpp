#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

public:

    Graph(int V){
        this->V = V;
        adj = new list<int> [V];
    }
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    
    void topSort();
};

void Graph::topSort(){
    //vector to store indegrees of all the nodes
    vector<int> in_degree(V,0);

    for(int u=0;u<V;u++){
        list<int>::iterator itr;
        for(itr=adj[u].begin();itr!=adj[u].end();itr++){
             in_degree[*itr]++;
        }
    }
    
    //queue is created and all nodes with indegree equal to zero are enqueued
    queue<int> q;
    for(int i=0;i<V;i++)
        if(in_degree[i]==0)
            q.push(i);
            
    //vector to store topological order
    vector<int> top_order;
    
    int countVisited=0;
    
    while(!q.empty()){
        int u=q.front();
        q.pop();    
        top_order.push_back(u);
        
        list<int>::iterator itr;
        for(itr=adj[u].begin();itr!=adj[u].end();itr++)
            if(--in_degree[*itr]==0)
                 q.push(*itr);
        
        countVisited++;
    }
    
    if(countVisited!=V){
        cout<<"There exists a cycle in a graph\n";
    }
    else{
        cout<<"Below is the topological sort of given graph:\n";
        for(int i=0;i<V;i++)
            cout<<top_order[i]<<" ";
        cout<<"\n";
    }
}

int main(){
    Graph g(6);
    
    g.addEdge(0,1);
    g.addEdge(1,5);
    g.addEdge(2,5);
    g.addEdge(2,4);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.addEdge(3,0);
    
    g.topSort();
    return 0;
}
