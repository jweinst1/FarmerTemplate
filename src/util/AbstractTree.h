//
// Created by Joshua Weinstein on 7/1/18.
//

#ifndef FARMER_ABSTRACTTREE_H
#define FARMER_ABSTRACTTREE_H

#include <algorithm>
#include "IndexUtil.h"

template<class T>
class AbstractTree
{
public:
    explicit AbstractTree(const T& headItem, unsigned long cap = 10):
            _headVal(headItem),
            _len(0),
            _cap(cap),
            _childNodes(new AbstractTree<T>*[_cap])
    {}
    ~AbstractTree() {
        for(unsigned long i = 0; i < _len; i++) delete _childNodes[i];
        delete[] _childNodes;
    }
private:
    T _headVal;
    unsigned long _len;
    unsigned long _cap;
    AbstractTree<T>** _childNodes;
};


#endif //FARMER_ABSTRACTTREE_H
