/*
 * search.h
 *
 *  Created on: 08/09/2015
 *      Author: lp1
 */

#ifndef SEARCH_H_
#define SEARCH_H_

/**
 * Return the position of element T
 */
template<class T>
int rSequentialSearch(T *vector, int size, T &element) {
    if (size == 0) return -1;
    if (*vector == element) return 0;

    int resultOfNextCall = rSequentialSearch(vector + 1, size - 1, element);

    return resultOfNextCall >= 0 ? 1 + resultOfNextCall : -1;
}

/**
 * Return the position of element T
 */
template<class T>
int rBinarySearch(T *vector, int size, T &element) {

    if (size == 0) return -1;
    int middle = size / 2;
    T *candidate = vector + middle;

    if (*candidate == element) return middle;

    int resultOfNextCall;
    if (element < *candidate) {
        resultOfNextCall = rBinarySearch(vector, middle, element);
        return resultOfNextCall >= 0 ? resultOfNextCall : -1;
    }

    resultOfNextCall = rBinarySearch(vector + middle + 1, size - middle -1, element);
    return resultOfNextCall >= 0 ?  middle + 1 + resultOfNextCall : -1;
}


#endif /* SEARCH_H_ */
