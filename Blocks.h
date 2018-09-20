#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>

class Blocks {
    private: 
        std::vector<std::stack<char>> towers;
        std::vector<std::stack<char>> goal;
    public:
        Blocks(std::fstream& file);
        Blocks(std::vector<std::stack<char>> towers, std::vector<std::stack<char>> goal);
        void display();
        std::vector<Blocks*> moves();
};