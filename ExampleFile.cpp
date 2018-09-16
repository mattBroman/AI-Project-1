#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <unordered_map>

using namespace std;

extern int goal_tests,max_queue_size; 

class State
{
public:
  vector<char*> stacks;
  State();
  State(vector<char*> input);
  void print();
  bool matches(State other);
  char* tostring();
};

extern float heuristic(State); // user must implement, estimated distance to goal

#define max(A,B) ((A>B)?A:B)

class Node
{
public:
  State state;
  Node* parent;
  int depth;
  float f;
  Node(State s);
  Node(State s,Node* par);
  vector<Node*> successors();
  bool goal_test(State goal);
  void print();
  void print_solution(int iters);
  void traceback();
};

class comparison
{
public:
  bool operator() (Node* lhs,Node* rhs) const
  {
    return (lhs->f > rhs->f); // because I want top() to be the node with the smallest score
  }
};
