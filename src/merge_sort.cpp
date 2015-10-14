//
// Created by gabriel on 10/4/15.
//

#include "merge_sort.h"

bool merge(int *setA, int sizeA, int *setB, int sizeB, bool break_on_duplicate) {
    int totalSize = sizeA + sizeB;
    int *originalArr = setA;
    int *aux = new int[totalSize];
    int *iterator = aux;
    bool duplicate = false;
    while (sizeA && sizeB) {
        if (*setA == *setB) {
            duplicate = true;
            if (break_on_duplicate) {
                delete aux;
                return true;
            }
        } else if (*setA > *setB){
            *iterator = *setB;
            setB++;
            sizeB--;
        } else{
            *iterator = *setA;
            setA++;
            sizeA--;
        }
        iterator++;
    }

    while (sizeA) {
        *iterator = *setA;
        setA++;
        sizeA--;
        iterator++;
    }

    while (sizeB) {
        *iterator = *setB;
        setB++;
        sizeB--;
        iterator++;
    }

    for (int i = 0; i < totalSize; i++) {
        *(originalArr+i) = *(aux+i);
    }

    delete aux;

    return duplicate;
}

void merge_sort(int *set, int size) {
    if (size <= 1) {
        // Se set tiver um elemento ou menos return
        return;
    }

    // Merge sort ambas as metades
    merge_sort(set, size / 2);
    merge_sort(set + size / 2, size - size / 2);

    // merge retorna true se houver o mesmo elemento na primeira e na segunda metade
    // em contrapartida set é ordenado
    merge(set, size / 2, set + size / 2, size - size / 2);
}
