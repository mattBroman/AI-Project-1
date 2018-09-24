#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>

class Blocks {
    private: 
        std::vector<std::vector<char>> towers;
        std::vector<std::vector<char>> goal;
    public:
        int nBlocks;
        Blocks(std::fstream& file);
        Blocks(std::vector<std::vector<char>>& towers, std::vector<std::vector<char>>& goal, int nBlocks);
        void display();
        void displayGoal();
        bool solution();
        std::vector<Blocks*> moves();
        std::vector<std::vector<char>> getTowers();
        std::vector<std::vector<char>> getGoal();
};