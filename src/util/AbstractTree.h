//
// Created by Joshua Weinstein on 7/1/18.
//

#ifndef FARMER_ABSTRACTTREE_H
#define FARMER_ABSTRACTTREE_H

#include <algorithm>


template<class T>
class AbstractTree
{
public:
    explicit AbstractTree(const T& headVal, unsigned long cap = 10): _headItem(headVal), _len(0), _cap(cap), _childNodes(new T[cap]) {}

    ~AbstractTree(){
        delete[] _childNodes;
    }

    bool isFull() const {
        return _len == _cap;
    }

    unsigned long getLen() const {
        return _len;
    }

    unsigned long getCap() const {
        return _cap;
    }

    AbstractTree& operator<<(const T& newItem) {
        if(isFull()) expand(2);
        _childNodes[_len++] = newItem;
        return *this;
    }

    T& operator[](unsigned long index) {
        return _childNodes[index];
    }
private:
    void expand(int factor) {
        _cap *= factor;
        T* newList = new T[_cap];
        std::copy(_childNodes, _childNodes + _len, newList);
        delete[] _childNodes;
        _childNodes = newList;
    }

    T _headItem;
    unsigned long _len;
    unsigned long _cap;
    T* _childNodes;
};



#endif //FARMER_ABSTRACTTREE_H
