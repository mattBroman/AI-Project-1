#include "Blocks.h"
using namespace std;

Blocks::Blocks(fstream& file) {
    if (!file.is_open()) {
        throw "yeet";
    }

    string input;
    getline(file, input);
    /* raw arrays are a pain and i can't figure out how to init
       a vector to a certain size from inside a class constructor
       so I don't need the first line, just gonna use push_back, This
       probabaly means I'll be using more memory than needed oh well
    */

    while (getline(file, input)) {
        vector<char> row;
        for ( char c : input) {
             row.push_back(c);
        }
        towers.push_back(row);
    }
}

void Blocks::display() {
    for (vector<char> row : towers) {
        for (char c : row) {
            cout << c;
        }
    cout << endl;
    }
}