//
// Created by Joshua Weinstein on 6/26/18.
//

#ifndef FARMER_CHARSEQ_H
#define FARMER_CHARSEQ_H

#include <iostream>
#include <cstdio>
#include <cstring>

// Acts as representation of sequence of chars.
// Not meant to be considered a full string.

class CharSeq {
public:

    explicit CharSeq(unsigned size);
    // Constructor for strings with null char
    explicit CharSeq(const char* string);
    // Constructor for section of chars.
    CharSeq(const char* chars, unsigned len);
    CharSeq(const CharSeq& other);
    ~CharSeq();

    unsigned getLen() const
    {
        return _len;
    }

    char& operator[] (unsigned index) const
    {
        return _seq[index % _len];
    }

    // prints to stdout
    void print();

    // Checks if direct match against string.
    bool match(const char* string) const;

    void fill(char ch) {
        std::fill(_seq, _seq + _len, ch);
    }

    bool operator==(const CharSeq &rhs) const;
    bool operator!=(const CharSeq &rhs) const;
    friend bool operator<(const CharSeq& lhs, const CharSeq& rhs);

    friend CharSeq operator+(const CharSeq& lhs, const CharSeq& rhs);

    void write(const char* chars);

    // Reads contents of sequence into desination.
    void read(char *destination) const;
private:
    char* _seq;
    unsigned _len;
};


#endif //FARMER_CHARSEQ_H
