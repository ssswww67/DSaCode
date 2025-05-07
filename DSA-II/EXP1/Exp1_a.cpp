#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void readFile(string& filename, vector<string>& arr) {
    ifstream file(filename);
    cout << "Reading : " << filename << endl;
    if (!file) {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            arr.push_back(line);
        }
    }
    file.close();
}
void writeFile(string& filename, vector<string>& arr) {
    ofstream file(filename);
    if (!file) {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    cout << "Writing in file : " << endl;
    for (auto line : arr) {
        file << line << endl;
    }
    file.close();
}
int main() {
    string inputFile = "Exp1_a.txt";
    vector<string> arr;
    //read input file
    readFile(inputFile, arr);
    sort(arr.begin(), arr.end());
    writeFile(inputFile, arr);
    return 0;
}