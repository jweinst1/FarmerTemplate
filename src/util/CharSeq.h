//
// Created by Joshua Weinstein on 6/26/18.
//

#ifndef FARMER_CHARSEQ_H
#define FARMER_CHARSEQ_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

// Determines size of buffer used in factory
#define CHAR_SEQ_FACT_BSIZE 1024


// Acts as representation of sequence of chars.
// Not meant to be considered a full string.
class CharSeq {
public:
    // empty sequence is nullptr
    CharSeq();
    // Constructs size of seq with all null chars
    explicit CharSeq(unsigned size);
    // Constructor for strings with null char
    explicit CharSeq(const char* string);
    // Constructor for section of chars.
    CharSeq(const char* chars, unsigned len);
    CharSeq(const CharSeq& other);
    ~CharSeq();
    /**
     * = Does not allow multi reference, simply makes a copy upon assignment.
     * @param other: A const reference to a different Char sequence
     * @return
     */
    CharSeq& operator=(const CharSeq& other);

    unsigned getLen() const
    {
        return _len;
    }

    char& operator[] (unsigned index) const
    {
        assert(_seq != nullptr);
        return _seq[index % _len];
    }
    // Checks if sequence is the empty sequence
    bool isEmpty() const
    {
        return _len == 0 && _seq == nullptr;
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

/**
 * Class that specializes in creating specific CharSeq, like for integers, booleans, or other
 * common text.
 */
class CharSeqFactory
{
public:
    CharSeqFactory();
    virtual ~CharSeqFactory();

    CharSeq fromInt(int value);
private:
    char _creatingBuffer[CHAR_SEQ_FACT_BSIZE];
};


#endif //FARMER_CHARSEQ_H
