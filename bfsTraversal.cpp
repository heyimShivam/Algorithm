// BFS Traversal in a graph from a given source vertex

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<list<int>> adj;

    public:
        Graph(int V);
        void addEdge(int v,int w);
        void BFS(int src);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph:: addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph:: BFS(int src) {
    vector<bool> visited;
    visited.resize(V,false);
    list<int> queue;

    visited[src] = true;
    queue.push_back(src);

    while(!queue.empty()) {
        src = queue.front();
        cout<<src<<" ";
        queue.pop_front();

        for(auto it : adj[src]) {
            if(!visited[it]) {
                visited[it] = true;
                queue.push_back(it);
        }
    }
}
}

int main() {

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout<< " Following is the Breadth First Traversal (starting from vertex 1) \n";

    g.BFS(1);

    return 0;
}


/*
output :
Following is the Breadth First Traversal (starting from vertex 1) 
1 2 0 3 
*/