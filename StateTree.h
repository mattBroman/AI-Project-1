#pragma once
#include <deque>
#include <fstream>
#include <string>
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
        long size();
};

class StateTree {
    private:
        Node* init;
        PriorityQueue frontier;
        std::unordered_map<std::string, int>* explored;
    public:
        StateTree(std::fstream* file);
        long iterations;
        Node* search();
        long maxFrontierSize;
        long nGoalTests;
};