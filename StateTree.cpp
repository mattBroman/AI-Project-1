#include "StateTree.h"
using namespace std;

PriorityQueue::PriorityQueue(Node* node) {
    queue.push_back(node);
}

PriorityQueue::PriorityQueue() {

}

void PriorityQueue::push(Node* node) {
    bool inserted = false;
    for (auto i = queue.begin(); i != queue.end(); i++) {
        if (node->score() < (*i)->score()) {
            queue.insert(i, node);
            inserted = true;
            break;
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
    Node* init = new Node(file);
    frontier.push(init);
}

Node* StateTree::search() {
    Node* solution = nullptr;
    while(!frontier.empty()) {
        Node* node = frontier.pop();
        node->display();
        if (node->solution()) {
            solution = node;
            break;
        }
        cout << "generating children" << endl;
        node->spawnChildren();
        vector<Node*> children = node->getChildren();
        /*explored.push_back(node);
        for (Node* viewed : explored) {
            bool repeat = false;
            for (Node* child: children) {
                if (child->compare(viewed)) {
                    repeat = true;
                    break;
                }
                if (!repeat) {
                    frontier.push(child);
                }
            }
        }*/
        for (auto child : children ) {
            frontier.push(child);
        }
    }
    return solution;
}