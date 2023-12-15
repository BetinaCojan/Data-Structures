#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "complex.h"

void complex::show() {
    if (im > 0) {
        std::cout << re << '+' << im << "i" << std::endl;
    } else {
        std::cout << re << im << "i" << std::endl;
    }
}

complex complex::conjugate() {
    complex conj;

    conj.re = re;
    conj.im = -im;
    
    return conj;
}

int main() {
    // variabila locala de tipul struct complex
    struct complex number;
    number.re = 0;
    number.im = 1;

    number.show();
    
    complex conj = number.conjugate();
    conj.show();

    // variabila de tip pointer, catre o zona de memorie alocata dinamic
    struct complex *pNumber = (struct complex *) malloc(sizeof(struct complex));
    pNumber->re = 5;
    pNumber->im = -9;

    pNumber->show();

    conj = pNumber->conjugate();
    conj.show();

    free(pNumber);

    return 0;
}