#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

struct Edge {
    string city1, city2;
    int weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
    private:
    map<string, string> parent;

    public:
    void makeSet(const vector<string>& cities) {
        for (const auto& city : cities) {
            parent[city] = city;
        }
    }

    string find(string city) {
        if (parent[city] != city)
            parent[city] = find(parent[city]); // Path compression
        return parent[city];
    }

    void unite(string a, string b) {
        string rootA = find(a);
        string rootB = find(b);
        if (rootA != rootB)
            parent[rootA] = rootB;
    }
};

int main() {
    ifstream file("map.txt");
    if (!file) {
        cerr << "Error: Cannot open file.\n";
        return 1;
    }

    vector<Edge> edges;
    map<string, bool> cityMap;
    string line;

    // Parse the file
    while (getline(file, line)) {
        stringstream ss(line);
        string city1, city2, distStr;
        getline(ss, city1, ',');
        getline(ss, city2, ',');
        getline(ss, distStr, ',');
        int weight = stoi(distStr);

        edges.push_back({ city1, city2, weight });
        cityMap[city1] = true;
        cityMap[city2] = true;
    }

    // Get all unique cities
    vector<string> cities;
    for (const auto& [city, _] : cityMap) {
        cities.push_back(city);
    }

    // Kruskal's algorithm
    DisjointSet ds;
    ds.makeSet(cities);
    sort(edges.begin(), edges.end()); // Sort edges by weight

    int totalWeight = 0;
    vector<Edge> mst;

    for (const auto& edge : edges) {
        if (ds.find(edge.city1) != ds.find(edge.city2)) {
            ds.unite(edge.city1, edge.city2);
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    // Print MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : mst) {
        cout << edge.city1 << " - " << edge.city2 << " (weight " << edge.weight << ")\n";
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
