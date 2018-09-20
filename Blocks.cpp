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
        stack<char> row;
        for ( char c : input) {
            row.push(c);
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
            goal.push_back(stack<char>());
        } 
    }
}

Blocks::Blocks(vector<stack<char>> towers, vector<stack<char>> goal) {
    
}

vector<Blocks*> Blocks::moves() {
    vector<Blocks*> returnVector;
    for (int i = 0; i < towers.size(); i++) {
        char tower = towers[i].top();
        towers[i].pop();
        for (int j = 0; j < towers.size(); j++) {
            
        }
    }
}

void Blocks::display() {
    cout << "entry was----------------" << endl;
    for (stack<char> row : towers) {
        stack<char> tempStack;
        while (!row.empty()) {
            char temp = row.top();
            row.pop();
        }
        while (!tempStack.empty()) {
            char temp = tempStack.top();
            cout << temp;
            row.push(temp);
        }
    cout << endl;
    }
    cout << "goal is ---------------------" << endl;
        for (stack<char> row : towers) {
        stack<char> tempStack;
        while (!row.empty()) {
            char temp = row.top();
            row.pop();
        }
        while (!tempStack.empty()) {
            char temp = tempStack.top();
            cout << temp;
            row.push(temp);
        }
    cout << endl;
    }
}