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

long PriorityQueue::size() {
    return queue.size();
}

StateTree::StateTree(fstream* file) {
    Node* init = new Node(file);
    explored = new unordered_map<string, int>();
    frontier.push(init);
    maxFrontierSize = 0;
    nGoalTests = 0;
    iterations = 0;
}

Node* StateTree::search() {
    Node* solution = nullptr;
    while(!frontier.empty() && iterations < 1000000) {
        iterations++;
        Node* node = frontier.pop();
        auto element = explored->find(node->hashKey);
        if (element == explored->end()) {// || node->iteration < element->second) {
            node->display();
            nGoalTests+=1;
            if (node->solution()) {
                solution = node;
                break;
            }
            cout << "generating children" << endl;
            node->spawnChildren();
            vector<Node*> children = node->getChildren();
            auto element = make_pair(node->hashKey, node->iteration);
            explored->insert(element);
            for (auto child : children ) {
                frontier.push(child);
            }
            if (maxFrontierSize < frontier.size()) {
                maxFrontierSize = frontier.size();
            }
        }
    }
    return solution;
}