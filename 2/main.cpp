#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"
#include <functional> 

int main() {
    auto integers = randomIntegers();
    std::cout << "Initial: " << integers << "\n";

    // TODO: make the sequence a bitonic sequence
    std::cout << "Bitonic: " << "TODO" << "\n\n";

    int half_length = integers.size() / 2;
    half_length += half_length % 2;//Increase if it is odd

    std::sort(integers.begin(), integers.begin() + half_length);//Increasing till middle
    std::sort(integers.begin() + half_length, integers.end(), std::greater <int> ());//Decreasing at middle

    
    std::cout << "Afterward: " << integers << "\n";

    return 0;
}