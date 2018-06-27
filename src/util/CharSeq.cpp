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

bool CharSeq::operator==(const CharSeq &rhs) const {
    if(_len != rhs.getLen()) return false;
    for (unsigned i = 0; i <_len; i++) {
        if(_seq[i] != rhs[i]) return false;
    }
    return true;
}

bool CharSeq::operator!=(const CharSeq &rhs) const {
    return !(rhs == *this);
}

CharSeq::CharSeq(const CharSeq &other): _seq(new char[other.getLen()]), _len(other.getLen()) {
    for(unsigned i = 0; i < _len ; i++) {
        _seq[i] = other[i];
    }
}

bool operator<(const CharSeq& lhs, const CharSeq& rhs) {
    int lhsTotal = 0;
    int rhsTotal = 0;
    for( unsigned i = 0; i < lhs._len ; i++) lhsTotal += lhs[i];
    for( unsigned j = 0; j < lhs._len ; j++) rhsTotal += rhs[j];
    return lhsTotal < rhsTotal;
}