#include <iostream>

int main() {
    double sum = 0.0;
    while (std::cin >> sum && sum != 0.0) {
        double currentSum = 0.0;
        int i = 0;
        for (i=2; currentSum<= sum; i++) {
            currentSum += 1.0 / static_cast<double>(i);
        }
        std::cout << i-2 << " card(s)" << std::endl;
    }
    return 1;
}
