//C++ program to print the DFS order traversal of a graph 

#include <bits/stdc++.h>

using namespace std;


//class GRaph represents the graph using the adjacent list representation
class Graph
{
    public: 
        map<int, bool> visited;
        map<int, list<int>> adj;
        void addEdge(int v, int n);
        void DFS(int v);
};

//Method to add edge to the graph
void Graph::addEdge(int v,int n) {
    adj[v].push_back(n);    //adding n in lsit v
}

//Method to traverse the vertices reachale from 'v'
void Graph::DFS(int v) {
    visited[v] = true;      //Marking the node as visited
    cout << v << endl;
    list<int>::iterator i;  //recurring all the connected vertices
    for(i=adj[v].begin();i!=adj[v].end();++i) {
        if(!visited[*i])
            DFS(*i);        //recursive call
    }
}

//Driver code
int main() {

    //Creating an example graph, and adding edges.
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(3,6);
    g.addEdge(4,5);
    g.addEdge(4,7);
    g.addEdge(5,2);

    cout << "DFS Traversla from vertex 0 is given below: " << endl;
    g.DFS(0);
    return 0;
}