// DFS

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    private:
    int V;
    vector<list<int>> adjList;

    public:
    Graph(int vertices) : V(vertices), adjList(vertices) { }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Order: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    int startNode = 0;
    g.DFS(startNode);

    return 0;
}
