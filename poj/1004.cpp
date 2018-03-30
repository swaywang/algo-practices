#include <iostream>

int main() {
    double balanceOfEachMonth = 0.0;
    double sum = 0.0;
    int numOfTotalMonth = 0;
    while (std::cin >> balanceOfEachMonth) {
        sum += balanceOfEachMonth;
        numOfTotalMonth++;
    }
    std::cout << "$" << sum / numOfTotalMonth << std::endl;
    return 1;
}
