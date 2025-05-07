#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
int main() {
    ifstream file("graph.txt");
    string line;
    map<int, vector<int>> graph;
    map<int, int> indegree;
    set<int> nodes;
    // Step 1: Read graph and build adjacency list and indegree map
    while (getline(file, line)) {
        stringstream ss(line);
        string fromStr, toStr;
        getline(ss, fromStr, ',');
        getline(ss, toStr);
        int from = stoi(fromStr);
        int to = stoi(toStr);
        graph[from].push_back(to);
        indegree[to]++;
        nodes.insert(from);
        nodes.insert(to);
    }
    // Initialize in-degrees for nodes with no incoming edges
    for (int node : nodes) {
        if (indegree.find(node) == indegree.end())
            indegree[node] = 0;
    }
    // Step 2: Queue all nodes with 0 in-degree
    queue<int> q;
    for (auto& entry : indegree) {
        if (entry.second == 0)

            q.push(entry.first);
    }
    // Step 3: Perform Kahn’s Algorithm
    vector<int> topoOrder;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        topoOrder.push_back(current);
        for (int neighbor : graph[current]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    // Step 4: Check if cycle exists
    if (topoOrder.size() != nodes.size()) {
        cout << "Cycle detected! Topological sort not possible.\n";
    } else {
        cout << "Topological Ordering:\n";
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
