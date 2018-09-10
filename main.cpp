#include <fstream>
#include "Blocks.h"
using namespace std;

int main(int argc, char** argv) {
    string fileName = string(argv[1]);
    fstream file(fileName);
    Blocks* blocks = new Blocks(file);
    //blocks->solve();
    blocks->display();
    return 0;
}