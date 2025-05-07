#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <limits>

using namespace std;

const int INF = 1e9; // A large number to represent infinity

int main() {
    ifstream file("map.txt");
    if (!file) {
        cerr << "Error: Cannot open input file.\n";
        return 1;
    }

    // Mapping city names to indices
    map<string, int> cityToIndex;
    map<int, string> indexToCity;
    int index = 0;

    vector<tuple<string, string, int>> edges;
    string line;

    // Read the file and gather all city names and edges
    while (getline(file, line)) {
        stringstream ss(line);
        string city1, city2, distStr;
        getline(ss, city1, ',');
        getline(ss, city2, ',');
        getline(ss, distStr, ',');

        int distance = stoi(distStr);
        edges.emplace_back(city1, city2, distance);

        if (cityToIndex.find(city1) == cityToIndex.end()) {
            cityToIndex[city1] = index;
            indexToCity[index] = city1;
            index++;
        }
        if (cityToIndex.find(city2) == cityToIndex.end()) {
            cityToIndex[city2] = index;
            indexToCity[index] = city2;
            index++;
        }
    }

    int V = index;
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // Initialize distances
    for (int i = 0; i < V; ++i)
        dist[i][i] = 0;

    for (const auto& [city1, city2, d] : edges) {
        int u = cityToIndex[city1];
        int v = cityToIndex[city2];
        dist[u][v] = d;
        dist[v][u] = d; // Because it's undirected
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Output all-pairs shortest path distances
    cout << "All-Pairs Shortest Path Distances:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << indexToCity[i] << " -> " << indexToCity[j] << ": ";
            if (dist[i][j] == INF)
                cout << "INF\n";
            else
                cout << dist[i][j] << "\n";
        }
        cout << endl;
    }

    return 0;
}
