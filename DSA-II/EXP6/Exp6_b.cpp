// Adjacency Matrix

#include <iostream>
#include <vector>

using namespace std;

class Graph {
    private:
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency matrix

    public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0)); // Initialize matrix with 0s
    }

    // Function to add an edge to the graph (undirected by default)
    void addEdge(int u, int v, bool isDirected = false) {
        adjMatrix[u][v] = 1;
        if (!isDirected) {
            adjMatrix[v][u] = 1; // Add reverse edge for undirected graph
        }
    }

    // Function to display the adjacency matrix
    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
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

    cout << "Graph represented using adjacency matrix:\n";
    g.display();

    return 0;
}
