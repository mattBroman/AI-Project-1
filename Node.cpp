#include "Node.h"
using namespace std;

Node::Node(fstream* file) {
    blocks = new Blocks(file);
    parent = nullptr;
}

Node::Node(Node* parent) {
    parent = parent;
    blocks = new Blocks(parent->blocks());
}

vector<Node*> spawnChildren() {
    
}