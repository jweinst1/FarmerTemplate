//
// Created by Joshua Weinstein on 6/28/18.
//

#include "CharStream.h"

CharStream::~CharStream() {
    delete[] _stream;
}

CharStream::CharStream(size_t capacity): _stream(new char[capacity]) , _len(0), _cap(capacity) {

}

void CharStream::expand(size_t addSize) {
    _cap += addSize;
    char* newStream = new char[_cap];
    std::copy(_stream, _stream + _len, newStream);
    delete[] _stream;
    _stream = newStream;
}

void CharStream::put(char ch) {
    if(isfull()) expand(CHARSTREAM_EXPAND_CH);
    _stream[_len++] = ch;
}

CharStream &CharStream::operator<<(char ch) {
    put(ch);
    return *this;
}

CharStream &CharStream::operator<<(const char *string) {
    while(*string) put(*string++);
    return *this;
}
