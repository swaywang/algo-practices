//191. Number of 1 Bits
#include <iostream>

int hammingWeight(uint32_t n) {
    int numberOfBits = 0;
    int mask = 1;
    for (int i=0; i<32; i++) {
        if ((n & mask) == mask) {
            numberOfBits++;
        }
        mask <<= 1;
    }
    return numberOfBits;
}

int hammingWeight2(uint32_t n) {
    int numberOfBits = 0;
    while (n != 0) {
        numberOfBits++;
        n &= (n - 1);
    }
    return numberOfBits;
}

int main() {
    int number = 0;
    std::cin >> number;
    std::cout << hammingWeight(number) << std::endl;
    std::cout << hammingWeight2(number) << std::endl;
    return 0;
}
