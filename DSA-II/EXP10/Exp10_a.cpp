#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
void dfs(int node, map<int, vector<int>>& graph, set<int>& visited, stack<int>& topoStack)
{
    visited.insert(node);
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited, topoStack);
        }
    }
    topoStack.push(node);
}
int main() {
    ifstream file("graph.txt");
    string line;
    map<int, vector<int>> graph;
    set<int> allNodes;
    // Step 1: Read the graph from file
    while (getline(file, line)) {
        stringstream ss(line);
        string fromStr, toStr;
        getline(ss, fromStr, ',');
        getline(ss, toStr);
        int from = stoi(fromStr);
        int to = stoi(toStr);
        graph[from].push_back(to);
        allNodes.insert(from);

        allNodes.insert(to);
    }
    set<int> visited;
    stack<int> topoStack;
    // Step 2: Perform DFS from each unvisited node
    for (int node : allNodes) {
        if (visited.find(node) == visited.end()) {
            dfs(node, graph, visited, topoStack);
        }
    }
    // Step 3: Output topological ordering
    cout << "Topological Ordering:\n";
    while (!topoStack.empty()) {
        cout << topoStack.top() << " ";
        topoStack.pop();
    }
    cout << endl;
    return 0;
}
