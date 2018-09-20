#pragma once
#include <vector>
#include "Blocks.h"

class Node {
    private:
        Blocks* blocks;
        Node* parent;
        std::vector<Node*> children;
    public:
        Node(fstream*);
        Node(Node*);
        int huristic();
        std::vector<Node*> spawnChildren();
};