#include <iostream>

int calcDamage(std::string &code) {
    int currentDamage = 1;
    int totalDamage = 0;
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == 'C') {
            currentDamage *= 2;
        }
        else if (code[i] == 'S') {
            totalDamage += currentDamage;
        }
    }
    return totalDamage;
}

bool isPossiable(std::string &code, int shieldMaxDamage) {
    int numOfTotalShotTime = 0;
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == 'S') {
            numOfTotalShotTime++;
        }
    }
    int minDamage = numOfTotalShotTime;
    if (minDamage > shieldMaxDamage) {
        return false;
    }
    return true;
}

bool hackTheRobotOneTime(std::string &code) {
    for (int i = code.length()-1; i > 0; i--) {
        if ( code[i] == 'S' && code[i-1] == 'C') {
            // swap
            char tmp = code[i];
            code[i] = code[i-1];
            code[i-1] = tmp;
            return true;
        }
    }
    return false;
}

int main() {
    int numOfCase = 0;
    int damage = 0;
    int totalDamage = 0;
    std::string code;
    std::cin >> numOfCase;
    for (int i = 0; i < numOfCase; i++) {
        int numOfSwap = 0;
        std::cin >> damage;
        std::cin >> code;
        std::cout << "Case #" << i+1 << ": ";
        if (!isPossiable(code, damage)) {
            std::cout << "IMPOSSIBLE" << std::endl;
        }
        else {
            totalDamage = calcDamage(code);
            int isHacked = true;
            while (totalDamage > damage && isHacked) {
                isHacked = hackTheRobotOneTime(code);
                if (isHacked) {
                    totalDamage = calcDamage(code);
                    numOfSwap++;
                }
            }
            std::cout << numOfSwap  << std::endl;
        }
    }

    return 0; 
}
