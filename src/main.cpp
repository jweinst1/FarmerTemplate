#include <iostream>
#include "util/CharSeq.h"

// Main Farmer File


int main(int argc, const char** argv) {
    CharSeq g("food\n");
    CharSeq f("food\n");
    g.print();
    f.print();
    CharSeq news = g + f;
    news.print();
    return 0;
}