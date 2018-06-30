//
// Created by Joshua Weinstein on 6/29/18.
//

#ifndef FARMER_ACCESSUTIL_H
#define FARMER_ACCESSUTIL_H

namespace IdxUtil {
    /**
     * Template for copying data between indexable classes.
     * @tparam T
     * @tparam IndexType // type of index used
     * @param destination
     * @param source
     * @param startIndex
     * @param endIndex
     */
    template <class DestinationType, class SourceType, class IndexType>
    void copyIndex(DestinationType& destination, const SourceType& source, IndexType startIndex, IndexType endIndex) {
        for(IndexType start = startIndex; start < endIndex; start++) {
            destination[start] = source[start];
        }
    }
    /**
     * General comparison function across slice of index.
     * @tparam LeftType
     * @tparam RightType
     * @tparam IndexType
     * @param lhs
     * @param rhs
     * @param startIndex : Index where comparison should start.
     * @param endIndex : Index where comparison should end.
     * @return
     */
    template <class LeftType, class RightType, class IndexType>
    bool isEqual(const LeftType& lhs, const RightType& rhs, IndexType startIndex, IndexType endIndex) {
        for(IndexType start = startIndex; start < endIndex; start++) {
            if(lhs[start] != rhs[start]) return false;
        }
        return true;
    };
}

#endif //FARMER_ACCESSUTIL_H
