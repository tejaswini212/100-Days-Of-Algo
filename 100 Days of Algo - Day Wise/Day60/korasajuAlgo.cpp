#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph {
	int V;
	list<int>* adj;

	//Filling the stack up according to their dfs traversal
	void fillOrder(int v, bool visited[], stack<int>& s) {
		visited[v] = true;

		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
			if (!visited[*i])
				fillOrder(*i, visited, s);
		s.push(v);
	}

	//DFS Traversal
	void DFSUtil(int v, bool visited[]) {
		visited[v] = true;
		cout << v << " ";
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
			if (!visited[*i])
				DFSUtil(*i, visited);
	}

public:
	//Instantiation
	Graph(int V) {
		this->V = V;
		adj = new list<int>[V];
	}

	//Adding edges in the graph
	void addEdge(int v, int w) {
		adj[v].push_back(w);
	}

	void kosaraju() {
		stack<int> s;
		//Initialize visited boolean array with false value
		bool* visited = new bool[V];
		for (int i = 0; i < V; i++)
			visited[i] = false;

		//if the node is not visited then traverse and fill the order in stack
		for (int i = 0; i < V; i++) 
			if (!visited[i])
				fillOrder(i, visited, s);

		//Reverse the graph edges to prevent the errors in algorithm
		Graph gr = getTranspose();
		for (int i = 0; i < V; i++)
			visited[i] = false;

		//Print the strongly connected components with DFS traversal line by line
		while (!s.empty()) {
			int v = s.top();
			s.pop();
			if (!visited[v]) {
				gr.DFSUtil(v, visited);
				cout << "\n";
			}
		}
	}

	//Reverse the edges in the new graph and pass it to the calling function
	Graph getTranspose() {
		Graph g(V);
		for (int v = 0; v < V; v++) {
			list<int>::iterator i;
			for (i = adj[v].begin(); i != adj[v].end(); ++i)
				g.adj[*i].push_back(v);
		}
		return g;
	}
};

int main() {
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);

	cout << "Below are the strongly connected components in given graph \n";
	g.kosaraju();

	return 0;
}