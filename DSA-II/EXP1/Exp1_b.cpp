#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
vector<string> split(string& line, char delimeter) {
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, delimeter)) {
        tokens.push_back(token);
    }
    return tokens;
}
vector<vector<string>> readCSV(string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "error reading file " << filename << endl;
        exit(1);
    }
    vector<vector<string>> data;
    string line;
    while (getline(file, line)) {
        data.push_back(split(line, ','));
    }
    file.close();
    return data;
}
void writeFile(string& filename, vector<vector<string>>& data) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "error writting file " << filename << endl;
        exit(1);
    }
    for (auto row : data) {
        file << row[0];
        for (int i = 1;i < row.size();++i) {
            file << "," << row[i];
        }
        file << '\n';
    }
    file.close();
}
void sortCSV(string& filename, int column) {
    vector<vector<string>> data = readCSV(filename);
    if (data.empty()) return;
    sort(data.begin() + 1, data.end(), [column](vector<string>& a, vector<string>& b) {
        return a[column] < b[column];
        });
    writeFile(filename, data);
    cout << "CSV file sorted and saved in : " << filename << endl;
}
int main() {
    string filename = "Exp1_b.csv";
    int column = 3;
    sortCSV(filename, column - 1);
    return 0;
}
