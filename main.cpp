#include <fstream>
#include <iostream>
#include <stack>
#include "Blocks.h"
#include "StateTree.h"
#include "Node.h"
using namespace std;

int main(int argc, char** argv) {
    string fileName = string(argv[1]);
    fstream* file = new fstream(fileName);
    StateTree* tree = new StateTree(file);
    cout << "starting search" << endl;
    Node* solution = tree->search();
    if (solution == nullptr) {
        cout << "no solution found" << endl;
        return 0;
    }
    else {
        cout << "solution found" << endl;
        stack<Node*> path;
        while (solution != nullptr) {
            Node* node = solution;
            path.push(node);
            solution = solution->getParent();
        }
        while (!path.empty()) {
            path.top()->display();
            path.pop();
        }
        return 0;
    }
}