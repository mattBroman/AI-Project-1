#include "Blocks.h"
using namespace std;

Blocks::Blocks(fstream& file) {
    if (!file.is_open()) {
        throw "yeet";
    }

    string input;
    getline(file, input);

    int spaceLoc = input.find(' ');
    int length = input.size() - spaceLoc;
    int nTowers = stoi(input.substr(0,length));
    int nBlocks = stoi(input.substr(spaceLoc));

    while (getline(file, input)) {
        vector<char> row;
        for ( char c : input) {
            row.push_back(c);
        }
        if (nTowers > 0) {
            towers.push_back(row);
            nTowers--;
        } 
        else {
            goal.push_back(row);
        }
    }

    if (goal.size() != towers.size()) {
        for (int i = 0; i < (towers.size() - goal.size()); i++) {
            goal.push_back(vector<char>(0));
        } 
    }
}

void Blocks::display() {
    cout << "entry was----------------" << endl;
    for (vector<char> row : towers) {
        for (char c : row) {
            cout << c;
        }
    cout << endl;
    }
    cout << "goal is ---------------------" << endl;
    for (vector<char> row : goal) {
        for (char c : row) {
            cout << c;
        }
    cout << endl;
    }
}