#include "utils/Random.h"


int randomOut(int n, int m) {
    std::random_device randomDevice;
    std::mt19937 rd(randomDevice());
    std::uniform_int_distribution<> intDistribution(n, m);

    int randomValue = intDistribution(rd);

    return randomValue;
}