#pragma once
#include <vector>
#include <fstream>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include "Blocks.h"

class Node {
    private:
        Blocks* blocks;
        Node* parent;
        std::vector<Node*> children;
        int huristic;
    public:
        int iteration;
        Node(std::fstream* file);
        std::string hashKey;
        Node(Blocks* blocks, Node* parent, int iteration);
        std::vector<Node*> getChildren();
        bool solution();
        int getHuristic();
        int score();
        void spawnChildren();
        void display();
        bool compare(Node*);
        Blocks* getBlocks();
        Node* getParent();
};