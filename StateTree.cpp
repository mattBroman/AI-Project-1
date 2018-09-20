#include "StateTree.h"
using namespace std;

PriorityQueue::PriorityQueue(Node* node) {
    queue.push_back(node);
}

void PriorityQueue::push(Node* node) {
    bool inserted = false;
    for (auto i = queue.begin(); i != queue.end(); i++) {
        if ((*i)->huristic() <= node->huristic()) {
            queue.insert(i, node);
            inserted = true;
        }
    }
    if (!inserted) {
        queue.push_back(node);
    }
}

Node* PriorityQueue::pop() {
    Node* returnNode = queue.front();
    queue.pop_front();
    return returnNode;
}

bool PriorityQueue::empty() {
    return queue.empty();
}

StateTree::StateTree(fstream* file) {
    init = new Node(file);
    PriorityQueue(init);
}

Node* StateTree::search() {
    Node* solution = nullptr;
    while(!frontier.empty()) {
        Node* node = frontier.pop();
        //do the things;
    }
    return solution;
}