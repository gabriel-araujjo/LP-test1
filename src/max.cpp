//
// Created by gabriel on 10/4/15.
//

#include "max.h"
#include "merge_sort.h"

void maximo(int *v, int ini, int fim, int *resultado) {
    // ordena o vetor entre as elementos v[ini] e v[fim]
    // ex: para ini = 2 e fim = 5
    // ordena os elementos v[2], v[3], v[4], v[5] em ordem crescente
    merge_sort(v + ini, fim - ini + 1);

    // coloca v[ini + fim], o ultimo elemento da ordenação, ou seja o maior em resultado
    *resultado = v[ini + fim];
}
