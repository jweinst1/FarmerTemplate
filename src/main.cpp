#include <iostream>
#include "util/CharSeq.h"

// Main Farmer File


int main(int argc, const char** argv) {
    CharSeq g("food", 4);
    CharSeq f("food", 4);
    g.print();
    std::cout << (g == f) << std::endl;
    CharSeq aa("Yo!!", 3);
    std::cout << (g < aa) << std::endl;
    std::cout << (aa < g) << std::endl;
    CharSeq b = aa;
    return 0;
}