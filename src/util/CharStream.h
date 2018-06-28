//
// Created by Joshua Weinstein on 6/28/18.
//

#ifndef FARMER_CHARSTREAM_H
#define FARMER_CHARSTREAM_H

#include <iostream>
#include <fstream>
#include <algorithm>

// Determines expansion amount for single char being full.
#define CHARSTREAM_EXPAND_CH 20

class CharStream {
public:
    explicit CharStream(size_t capacity = 10);
    virtual ~CharStream();

    size_t getLen() const
    {
        return _len;
    }

    size_t getCap() const
    {
        return _cap;
    }

    bool isfull() const
    {
        return _len == _cap;
    }
    // Writes single char to stream.
    // Meant to be called by higher functions.
    void put(char ch);
private:
    // Allows stream to expand in size.
    void expand(size_t addSize);
private:
    char* _stream;
    size_t _len;
    size_t _cap;
};


#endif //FARMER_CHARSTREAM_H
