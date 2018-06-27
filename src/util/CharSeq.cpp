//
// Created by Joshua Weinstein on 6/26/18.
//

#include "CharSeq.h"

CharSeq::~CharSeq() {
    delete[] _seq;
}

CharSeq::CharSeq(const char *chars, unsigned len): _seq(new char[len]), _len(len) {
    for (unsigned i = 0; i <len ; i++) {
        _seq[i] = chars[i];
    }
}

void CharSeq::print() {
    for (unsigned i = 0; i <_len ; i++){
        std::putc(_seq[i], stdout);
    }
}
