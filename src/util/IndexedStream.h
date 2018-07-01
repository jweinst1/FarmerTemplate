//
// Created by Joshua Weinstein on 6/30/18.
//

#ifndef FARMER_INDEXEDSTREAM_H
#define FARMER_INDEXEDSTREAM_H

#include <vector>

template<class ItemType, class IndexType>
class IndexedStream {
public:
    IndexedStream() {}
    ~IndexedStream(){
        delete _items;
        delete _inputIndexes;
    }

    size_t itemCount() const {
        return _items.size();
    }

    size_t indexesCount() const {
        return _inputIndexes.size();
    }

    void addItem(const ItemType& item) {
        _items.push_back(item);
    }

    void addIndexedItem(const ItemType& item) {
        _items.push_back(item);
        _inputIndexes.push_back(_items.size() - 1);
    }

    ItemType& operator[](IndexType index)  {
        return _items[index];
    }

private:
    std::vector<ItemType> _items;
    std::vector<IndexType> _inputIndexes;
};



#endif //FARMER_INDEXEDSTREAM_H
