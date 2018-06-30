#include <iostream>
#include "util/CharSeq.h"

// Main Farmer File


int main(int argc, const char** argv) {
    CharSeq g("food\n");
    CharSeq f("food\n");
    g.print();
    f.print();
    CharSeq news = g + f + f;
    news.print();
    std::cout << (g == f) << std::endl;
    return 0;
}