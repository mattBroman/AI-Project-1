#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class Blocks {
    private: 
        std::vector<std::vector<char>> towers;
        std::vector<std::vector<char>> goal;
        std::vector<Blocks*> children;
        int iteration;
    public:
        Blocks(std::fstream& file);
        Blocks(const Blocks& copy);
        void generateChildern();
        void display();
        bool isFinsihed();
        int huristic();
};