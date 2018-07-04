#include <iostream>
#include <AbstractTree.h>
#include "util/CharSeq.h"

// Main Farmer File


int main(int argc, const char** argv) {
    AbstractTree<int> g(8);
    std::cout << g.getHead() << std::endl;
    g << 5 << 8 << 7 << 3;
    g[0] << 4;
    std::cout << g[0][0].getHead() << std::endl;
    CharSeqFactory aa;
    return 0;
}