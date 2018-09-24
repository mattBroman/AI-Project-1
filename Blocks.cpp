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
    nBlocks = stoi(input.substr(spaceLoc));

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
            goal.push_back(vector<char>());
        } 
    }
    this->display();
    this->displayGoal();
}

Blocks::Blocks(vector<vector<char>>& towers, vector<vector<char>>& goal, int nBlocks) {
    this->nBlocks = nBlocks;
    while (this->towers.size() < towers.size()) {
        vector<char> vec;
        this->towers.push_back(vec);
    }
    while (this->goal.size() != goal.size()) {
        vector<char> vec;
        this->goal.push_back(vec);
    }
    
    for (int i = 0; i < towers.size(); i++) {
        for (int j = 0; j < towers[i].size(); j++) {
            this->towers[i].push_back(towers[i][j]);
        }
    }
    for (int i = 0; i < goal.size(); i++) {
        for (int j = 0; j < goal[i].size(); j++) {
            this->goal[i].push_back(goal[i][j]);
        }
    }
}

vector<Blocks*> Blocks::moves() {
    vector<Blocks*> returnVector;
    for (int i = 0; i < towers.size(); i++) {
        if (!towers[i].empty()) {
            char letter = towers[i].back();
            towers[i].pop_back();
            for (int j = 0; j < towers.size(); j++) {
                if (i != j) {
                    towers[j].push_back(letter);
                    Blocks* blocks = new Blocks(towers, goal, nBlocks);
                    returnVector.push_back(blocks);
                    towers[j].pop_back();
                }
            }
        towers[i].push_back(letter);
        }
    }
    return returnVector;
}

void Blocks::display() {
    cout << "state------------------------" << endl;
    for (auto i = towers.begin(); i != towers.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            cout << *j;
        }
        cout << endl;
    }
}

void Blocks::displayGoal() {
    cout << "goal-------------------------------" << endl;
    for (auto i = goal.begin(); i != goal.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            cout << *j;
        }
        cout << endl;
    }
}

bool Blocks::solution() {
    for (int i = 0; i < towers.size(); i++) {
        if (towers[i].size() != goal[i].size()) {
            return false;
        }
        for (int j = 0; j < towers[i].size(); j++) {
            if (towers[i][j] != goal[i][j]) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<char>> Blocks::getGoal() {
    return goal;
}

vector<vector<char>> Blocks::getTowers() {
    return this->towers;
}