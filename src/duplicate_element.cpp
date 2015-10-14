/*
 * merge_sort.cpp
 *
 *  Created on: 08/09/2015
 *      Author: lp1
 */

#include "duplicate_element.h"
#include "merge_sort.h"

bool duplicate_elements_test(int *set, int size){

	if (size <= 1) {
		// Se set tiver um elemento ou menos não há duplicatas
		return false;
	}

    // Testa se há duplicatas na primeira metade do array,
    // se não houver duplicata, estará ordenada
	bool a1 = duplicate_elements_test(set, size / 2);
	if (a1) return true;

    // Teste se há duplicatas na segunda metade do array
    // se não houver duplicata, estará ordenada
	bool a2 = duplicate_elements_test(set + size / 2, size - size / 2);
	if (a2) return true;

    // merge retorna true se houver o mesmo elemento na primeira e na segunda metade
    // em contrapartida set é ordenado
	return merge(set, size / 2, set + size / 2, size - size / 2, true);
}


