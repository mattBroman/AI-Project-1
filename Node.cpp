#include "Node.h"
using namespace std;

Node::Node(fstream* file) {
    blocks = new Blocks(*file);
    this->hashKey = blocks->genHashKey();
    parent = nullptr;
    iteration = 0;
    huristic = getHuristic();
}

Node::Node(Blocks* blocks, Node* parent, int iteration) {
    this->parent = parent;
    this->blocks = blocks;
    this->hashKey = blocks->genHashKey();
    this->iteration = ++iteration;
    huristic = getHuristic();

}

void Node::spawnChildren() {
    vector<Blocks*> moves = blocks->moves();
    for (Blocks* blocks : moves) {
        Node* node = new Node(blocks, this, iteration);
        children.push_back(node);
    }
}

vector<Node*> Node::getChildren() {
    return children;
}

int Node::getHuristic() {
    int score = 0;
    auto towers = blocks->getTowers();
    auto goal = blocks->getGoal();
    unordered_map<char, pair<int, int>> locations;
    for (int i = 0; i < goal.size(); i++) {
        for (int j = 0; j < goal[i].size(); j++) {
            pair<int, int> cord = make_pair(i, j);
            pair<char, pair<int, int>> element = make_pair(goal[i][j], cord);
            locations.insert(element);
        };
    }
    for (int i = 0; i < towers.size(); i++) {
        for (int j = 0; j < towers[i].size(); j++) {
            auto element = locations.find(towers[i][j]);
            int xScore = abs(i - element->second.first);
            int yScore = abs(j - element->second.second);
            double distance = sqrt(pow(xScore,2) + pow(yScore,2));
            if (distance == 0) {
                bool stacked = true;
                for (int k = 0; k < j; k++) {
                    if (towers[i][k] != goal[i][k]) {
                        stacked = false;
                        break;
                    }
                }
                if (stacked) {
                    score -=  (goal[i].size()) * 2;
                }
                else {
                    score += goal[i].size() - j;
                }
            }
            else if (xScore != 0) {
                score +=  towers[element->second.first].size();
            }
            else {
                score += towers[i].size() * distance;
            }     
        }
    }
    return score;

}

int Node::score() {
    return huristic + iteration;
}

bool Node::solution() {
    return blocks->solution();
}

void Node::display() {
    cout << "iteration: " << iteration << endl;
    cout << "score: " << score() << endl;
    blocks->display();
}

Node* Node::getParent() {
    return parent;
}

Blocks* Node::getBlocks() {
    return blocks;
}

bool Node::compare(Node* node) {
    Blocks* otherBlocks = node->getBlocks();
    vector<vector<char>> otherTowers = otherBlocks->getTowers();
    vector<vector<char>> thisTowers = this->blocks->getTowers();
    if (otherTowers.size() != thisTowers.size()) {
        return false;
    }
    else {
        for (int i = 0; i < thisTowers.size(); i++) {
            if(thisTowers.at(i).size() != otherTowers.at(i).size()) {
                return false;
            }
            else {
                for (int j = 0; j < thisTowers.at(i).size(); j++) {
                    if (thisTowers.at(i).at(j) != otherTowers.at(i).at(j)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}