#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class Blocks {
    private: 
        std::vector<std::vector<char>> towers;
    public:
        Blocks(std::fstream& file);
        void parse();
        void solve();
        void display();
};