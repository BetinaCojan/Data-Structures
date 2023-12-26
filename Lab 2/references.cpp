#include <iostream>

//1- Funcție care interschimbă valorile a două variabile folosind referințe
void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int& getReference(int &a) {
    return a;
}

int main() {
    int x = 5, y = 10;
    int val = 42;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;

    // Apelul funcției cu referințe în listele de parametri
    swapValues(x, y);

    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    //2- Utilizarea referinței returnate de funcție
    int &ref = getReference(val);

    std::cout << "Initial value of val: " << val << std::endl;

    // Modificarea valorii prin intermediul referinței
    ref = 100;

    std::cout << "Modified value of val: " << val << std::endl;


    return 0;
}