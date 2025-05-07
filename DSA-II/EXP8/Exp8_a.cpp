#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

class Graph {
    private:
    map<string, vector<pair<string, int>>> adjList;

    public:
    void addEdge(const string& city1, const string& city2, int distance, bool isDirected = false) {
        adjList[city1].push_back({ city2, distance });
        if (!isDirected) {
            adjList[city2].push_back({ city1, distance });
        }
    }

    void display() {
        for (const auto& entry : adjList) {
            cout << entry.first << " --> ";
            for (const auto& neighbor : entry.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    ifstream file("map.txt");
    string line;

    if (!file) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string city1, city2, distanceStr;
        getline(ss, city1, ',');
        getline(ss, city2, ',');
        getline(ss, distanceStr, ',');

        int distance = stoi(distanceStr);
        g.addEdge(city1, city2, distance);
    }

    cout << "Graph built from file:\n";
    g.display();

    return 0;
}
