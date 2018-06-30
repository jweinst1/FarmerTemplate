//
// Created by Joshua Weinstein on 6/26/18.
//

#include "CharSeq.h"
#include <algorithm>

CharSeq::~CharSeq() {
    delete[] _seq;
}

CharSeq::CharSeq(const char *string): _len(0) {
    const char* counter = string;
    while(*counter++) _len++;
    _seq = new char[_len];
    for(unsigned i = 0; i < _len; i++) {
        _seq[i] = string[i];
    }
}

CharSeq::CharSeq(const char *chars, unsigned len): _seq(new char[len]), _len(len) {
    for (unsigned i = 0; i <len ; i++) {
        _seq[i] = chars[i];
    }
}

CharSeq::CharSeq(unsigned size): _seq(new char[size]), _len(size) {
    std::fill(_seq, _seq + _len, '\0');
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

void CharSeq::read(char *destination) const {
    for(unsigned i = 0; i < _len; i++) {
        destination[i] = _seq[i];
    }
}

bool CharSeq::match(const char *string) const {
    for(unsigned i = 0; i < _len; i++) {
        if(_seq[i] != string[i]) return false;
    }
    return true;
}

void CharSeq::write(const char *chars) {
    for(unsigned i = 0; i< _len ; i++) {
        _seq[i] = chars[i];
    }
}

CharSeq operator+(const CharSeq &lhs, const CharSeq &rhs) {
    unsigned lhsLen = lhs.getLen();
    unsigned rhsLen = rhs.getLen();
    CharSeq newSeq(lhs.getLen() + rhs.getLen());
    for(unsigned i =0; i < lhsLen; i++) newSeq[i] = lhs[i];
    for(unsigned i=lhsLen; i < (lhsLen + rhsLen); i++) newSeq[i] = rhs[i];
    return newSeq;
}




