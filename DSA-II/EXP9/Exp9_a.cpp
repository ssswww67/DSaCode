#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <set>

using namespace std;

struct Edge {
    string to;
    int weight;
};

class Graph {
    private:
    map<string, vector<Edge>> adjList;
    set<string> cities;

    public:
    void addEdge(const string& u, const string& v, int w) {
        adjList[u].push_back({ v, w });
        adjList[v].push_back({ u, w });
        cities.insert(u);
        cities.insert(v);
    }

    void primMST(const string& startCity) {
        map<string, int> key;
        map<string, string> parent;
        map<string, bool> inMST;

        for (const string& city : cities) {
            key[city] = INT_MAX;
            parent[city] = "";
            inMST[city] = false;
        }

        key[startCity] = 0;

        auto cmp = [&key](const string& a, const string& b) {
            return key[a] > key[b];
            };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        pq.push(startCity);

        while (!pq.empty()) {
            string u = pq.top();
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (const Edge& edge : adjList[u]) {
                string v = edge.to;
                int weight = edge.weight;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push(v);
                }
            }
        }

        // Print MST and total weight
        int totalWeight = 0;
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (const string& city : cities) {
            if (parent[city] == "")
                cout << city << " (weight 0)\n";
            else
                cout << city << " (weight " << key[city] << ")\n";

            totalWeight += key[city];
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    ifstream file("map.txt");
    if (!file) {
        cerr << "Error: Cannot open input file.\n";
        return 1;
    }

    Graph g;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string city1, city2, distStr;
        getline(ss, city1, ',');
        getline(ss, city2, ',');
        getline(ss, distStr, ',');

        int distance = stoi(distStr);
        g.addEdge(city1, city2, distance);
    }

    g.primMST("B"); // You can change the starting city

    return 0;
}
