//============================================================================
// Prova 1 de Linguagem de prorgamação, Prof. Bel
//
// A questão 1 está nos arquivos search.h e search.cpp
// A questão 2 está nos arquivos max.h e max.cpp
// A questão 3 está nos arquivos duplicate_element.h e duplicate_element.cpp
// A questão 4 está nos arquivos poll.h e poll.cpp
//============================================================================

#include <iostream>
#include "search.h"
#include "max.h"
#include "duplicate_element.h"
#include "poll.h"

void test_search();

void test_max();

void test_duplicate();

void test_poll();

using namespace std;

int main() {

    test_search();

    test_max();

    test_duplicate();

    test_poll();

	return 0;
}

void test_search() {
    int a[] = {1,7,3,5,6,9,2};
    int element = 7;

    std::cout << "The position of element 7 is " << rSequentialSearch(a, 7, element) << std::endl;

    int b[] = {1,4,5,6,7,8,9};
    std::cout << "The position of element 7 is " << rBinarySearch(b, 7, element) << std::endl;
}

void test_max() {
    int a[] = {26,30,25,14,20,13,32,24,30,15,34,29,23,21,1,1,6};

    int max;
    maximo(a, 0, 2, &max);

    std::cout << "o valor máximo entre [1,1,6] é "<< max << "!" << std::endl;
}

void test_duplicate() {
    int a[] = {2,2};

    std::cout << "There is" << (duplicate_elements_test(a,2) ? "": " not") << " duplicate elements" << std::endl;

    int b[] = {};

    std::cout << "There is" << (duplicate_elements_test(b,0) ? "": " not") << " duplicate elements" << std::endl;

    int c[] = {1,2,3,4,5,6,7,8,9,0};

    std::cout << "There is" << (duplicate_elements_test(c,10) ? "": " not") << " duplicate elements" << std::endl;
}

void test_poll() {
    int a[] = {32,22,20,5,14,27,27,24,34,10,7,9,10,18,6,32,4,27,28,12,6,16,31,2,33,16,23,26,19,3,15,8,35,3,13,22,26,5,12,7,20,27,21,17,28,26,2,14,23,23,16,8,19,16,19,2,22,14,34,16,20,29,32,30,10,6,26,19,17,6,6,29,28,32,22,6,6,25,5,10,25,28,11,21,35,24,5,2,31,33,22,30,27,10,2,29,18,19,20,13};

    std::cout << get_winner(a, 100) << std::endl;

    print_stats(a, 100);
}
