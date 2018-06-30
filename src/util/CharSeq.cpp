//
// Created by Joshua Weinstein on 6/26/18.
//

#include "CharSeq.h"
#include "IndexUtil.h"

CharSeq::~CharSeq() {
    delete[] _seq;
}

CharSeq::CharSeq(): _seq(nullptr), _len(0) {

}

CharSeq::CharSeq(const char *string): _len(0) {
    const char* counter = string;
    while(*counter++) _len++;
    _seq = new char[_len];
    IdxUtil::copyIndex(_seq, string, (unsigned)0, _len);
}

CharSeq::CharSeq(const char *chars, unsigned len): _seq(new char[len]), _len(len) {
    IdxUtil::copyIndex(_seq,  chars, (unsigned)0, _len);
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
    return IdxUtil::isEqual(_seq, rhs, (unsigned)0, _len);
}

bool CharSeq::operator!=(const CharSeq &rhs) const {
    return !(rhs == *this);
}

CharSeq::CharSeq(const CharSeq &other): _seq(new char[other.getLen()]), _len(other.getLen()) {
    IdxUtil::copyIndex(_seq, other, (unsigned)0, _len);
}

bool operator<(const CharSeq& lhs, const CharSeq& rhs) {
    int lhsTotal = 0;
    int rhsTotal = 0;
    for( unsigned i = 0; i < lhs._len ; i++) lhsTotal += lhs[i];
    for( unsigned j = 0; j < lhs._len ; j++) rhsTotal += rhs[j];
    return lhsTotal < rhsTotal;
}

void CharSeq::read(char *destination) const {
    IdxUtil::copyIndex(destination, _seq, (unsigned)0, _len);
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
    unsigned lhsLen = lhs._len;
    unsigned rhsLen = rhs._len;
    CharSeq newSeq(lhs.getLen() + rhs.getLen());
    for(unsigned i =0; i < lhsLen; i++) newSeq[i] = lhs[i];
    for(unsigned i=lhsLen; i < (lhsLen + rhsLen); i++) newSeq[i] = rhs[i];
    return newSeq;
}

CharSeq &CharSeq::operator=(const CharSeq &other) {
    if(*this != other) {
        // deletes current pointer and copies new one.
        delete[] _seq;
        _len = other.getLen();
        _seq = new char[_len];
        for (unsigned i = 0; i < _len; i++) {
            _seq[i] = other[i];
        }
    }
    return *this;
}

