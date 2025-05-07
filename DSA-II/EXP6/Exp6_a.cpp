// Adjacency list

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    private:
    int V; // Number of vertices
    vector<list<int>> adjList; // Adjacency list

    public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    // Function to add an edge to the graph (undirected by default)
    void addEdge(int u, int v, bool isDirected = false) {
        adjList[u].push_back(v);
        if (!isDirected) {
            adjList[v].push_back(u); // Add reverse edge for undirected graph
        }
    }

    // Function to display the adjacency list
    void display() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << " --> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    Graph g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Graph represented using adjacency list:\n";
    g.display();

    return 0;
}
