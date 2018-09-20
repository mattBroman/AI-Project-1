#pragma once
#include <deque>
#include "Node.h"


struct PriorityQueue {
    private: 
        std::deque<Node*> queue;
    public:
        PriorityQueue(Node*);
        void push(Node*);
        Node* pop();
        bool empty();
};

class StateTree {
    private:
        Node* init;
        PriorityQueue frontier;
    public:
        StateTree(fstream*);
        Node* search();
};