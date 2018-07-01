#include <iostream>
#include "util/CharSeq.h"
#include "util/AbstractTree.h"

// Main Farmer File


int main(int argc, const char** argv) {
    AbstractTree<int> g(3);
    g << 5 << 6 << 4 << 3 << 2 << 5 << 3;
    std::cout << g.isFull() << std::endl;
    return 0;
}