#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <cfloat>//For DBL_MIN and DBL_MAX
#include "Utility.h"
#include <numeric> //For accumulate()
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    // TODO: print the average price and price range

    std::vector<double> cars_price;
    double maxPrice = DBL_MIN, minPrice = DBL_MAX;
    double avg = 0, range = 0;
    //Extracting price from cars and put into cars_price
    std::transform(cars.cbegin(), cars.cend(), std::back_inserter(cars_price), [](const Car &car){
           return car.price();
       });

    //Using accumulate to add them all up, then divide by the size to calculate the average value
    avg = std::accumulate(cars_price.begin(), cars_price.end(), 0.0) / cars_price.size();

    //Finding max, min
    maxPrice = *std::max_element(cars_price.begin(), cars_price.end());
    minPrice = *std::min_element(cars_price.begin(), cars_price.end());
    range = maxPrice - minPrice;

    std::cout << "The average price is: $" << avg << "\n";

    std::cout << "The range is: $" << range << "\n";
}