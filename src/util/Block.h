//
// Created by Joshua Weinstein on 6/29/18.
//

#ifndef FARMER_BLOCK_H
#define FARMER_BLOCK_H

#include <cassert>

/** Block: Template class for fixed size array.
 *
 * @tparam T Generic type for multi-use fixed size dynamic array.
 */
template<class T>
class Block {
public:
   explicit Block(unsigned long _size) : _size(_size), _items(new T[_size]) {
       assert(_size > 0);
   }
    ~Block() { delete[] _items; }

    unsigned long getSize() const
    {
        return _size;
    }

    T& operator[](unsigned long index) {
        return _items[index % _size];
    }

private:
    unsigned long _size;
    T* _items;
};


#endif //FARMER_BLOCK_H
