#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);
bool checkPrime(int a);//Checking whether an integer is a prime or not

int main() {
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";

    //std::cout << (checkPrime(12) ? "\nyes\n" : "\nno\n");
    return 0;
}
//Checking whether an integer is a prime or not
bool checkPrime(int a){
    //prime factorization of any integer below 100 all consists 2,3,5 and 7 (Except prime numbers, which has only its self)
    switch (a){
        case 0: case 1: //Mathematically speaking, 0 and 1 are not prime
            return false;
        case 2: case 3: case 5: case 7:
            return true;
    }

    if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0 || a % 7 == 0){
        return false;
    }
    return true;
}
bool anyPrime(const std::vector<int>& values) {
    // TODO: return true if any of the values are prime numbers
    auto result = false;
    for (int i : values){
        result |= checkPrime(i);
    }
    return result;
}