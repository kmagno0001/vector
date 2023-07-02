#include <iostream>
#include "Vector.hpp"


int main() {
    Vec<int> vetor {1,2,3,4,5};
    
    vetor << 8;
    vetor << 9;
    vetor << 5;
    vetor << 81;
    vetor << 91;
    vetor << 52;
    vetor << 8;
    vetor << 9;
    vetor << 5;
    vetor << 81;
    vetor << 91;
    vetor << 52;
    vetor << 8;
    vetor << 9;
    vetor << 5;
    vetor << 81;
    vetor << 91;
    vetor << 52;
    vetor << 8;
    vetor << 9;
    vetor << 5;
    vetor << 81;
    vetor << 91;
    vetor << 52;
    vetor << 58;
    vetor << 91;
    vetor << 52;
    vetor << 58;
    vetor << 58;
    vetor >> 4;
    vetor >> 91;

    std::cout << vetor.get_len();

    std::cout << "\n";

    for (auto i : vetor) {
        std::cout << i;
    }

    std::cout << "\n" << vetor.get_capacity();

    return 0;
}