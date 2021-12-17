#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

//Added comparing function
bool Comp (const Car& first, const Car& second) {
    if (first.price() == second.price()){
        return first.vin() > second.vin();
    }
    return first.price() > second.price();
}

int main() {
    auto cars = randomCars();
    std::cout << "Initial: " << cars << "\n";

    // TODO: print out the cars in reverse order
    std::cout << "\nReversed: " << "TODO" << "\n";

    std::sort(std::begin(cars),std::end(cars), Comp);

    std::cout << "After reversing: " << cars << "\n";
}