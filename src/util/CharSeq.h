//
// Created by Joshua Weinstein on 6/26/18.
//

#ifndef FARMER_CHARSEQ_H
#define FARMER_CHARSEQ_H

#include <iostream>
#include <cstdio>

// Acts as immutable representation of sequence of chars.
// Not meant to be considered a full string.

class CharSeq {
public:
    CharSeq(const char* chars, unsigned len);
    ~CharSeq();

    unsigned getLen() const
    {
        return _len;
    }

    const char& operator[] (unsigned index) const
    {
        return _seq[index % _len];
    }

    // prints to stdout
    void print();

    bool operator==(const CharSeq &rhs) const;

    bool operator!=(const CharSeq &rhs) const;

private:
    char* _seq;
    unsigned _len;
};


#endif //FARMER_CHARSEQ_H
