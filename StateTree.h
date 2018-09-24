#pragma once
#include <deque>
#include <fstream>
#include "Node.h"


struct PriorityQueue {
    private: 
        std::deque<Node*> queue;
    public:
        PriorityQueue(Node*);
        PriorityQueue();
        void push(Node*);
        Node* pop();
        bool empty();
};

class StateTree {
    private:
        Node* init;
        PriorityQueue frontier;
        std::vector<Node*> explored;
    public:
        StateTree(std::fstream* file);
        Node* search();
};