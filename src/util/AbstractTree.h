//
// Created by Joshua Weinstein on 7/1/18.
//

#ifndef FARMER_ABSTRACTTREE_H
#define FARMER_ABSTRACTTREE_H

#include <algorithm>
#include <cassert>

/**
 * Generic Tree class with arbitrary number of child nodes
 * @tparam T : Template type
 */
template<class T>
class AbstractTree
{
public:
    /**
     * Constructor
     * @param headItem : The item to be held as the node's value.
     * Note: Types used here must have = operator and by copyable.
     * @param cap : The reserved memory for child nodes, can expand.
     */
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

    unsigned long getLen() const {
        return _len;
    }

    unsigned long getCap() const {
        return _cap;
    }

    bool isFull() const {
        return _len == _cap;
    }

    const T& getHead() const {
        return _headVal;
    }

    void setHead(const T& newVal) {
        _headVal = newVal;
    }

    /**
     * Appends new child node.
     * @param childVal The value used in construction of new node.
     */
    void appendChild(const T& childVal) {
        if(isFull()) expand();
        _childNodes[_len++] = new AbstractTree<T>(childVal);
    }

    AbstractTree<T>& operator<<(const T& childVal) {
        appendChild(childVal);
        return *this;
    }

    AbstractTree<T>& operator[](unsigned long index) {
        assert(index < _len);
        return *(_childNodes[index]);
    }
private:
    void expand(int factor = 2) {
        _cap *= factor;
        AbstractTree<T>** newChildren = new AbstractTree<T>*[_cap];
        std::copy(_childNodes, _childNodes + _len, newChildren);
        delete[] _childNodes;
        _childNodes = newChildren;
    }
private:
    T _headVal;
    unsigned long _len;
    unsigned long _cap;
    AbstractTree<T>** _childNodes;
};


#endif //FARMER_ABSTRACTTREE_H
