#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
#include <string>
#include "Utility.h"
#include <math.h>
#include "Car.h"

std::vector<int> createElevationMap();
int solve(const std::vector <int> &map);

int main() {
    auto range = createElevationMap();
  
    std::cout << "Elevation Map: " << range << "\n";

    // TODO: print out the amount of trapped water after it rains

    std::cout << solve(range) <<" units of water have been trapped after it rained";
}

std::vector<int> createElevationMap() {
    // generate elevation data
    std::mt19937 generator{ std::random_device{}() };
    std::exponential_distribution<> elevationDist{ 0.5 };
    auto elevationCreator = [&generator, &elevationDist]() { 
        return static_cast<int>(elevationDist(generator));
    };
    auto elevationMap = randomVectorOfObjects<int, decltype(elevationCreator)>(elevationCreator);

    // ensure there is only one highest peak
    auto firstMaxPeakIt = std::max_element(elevationMap.begin(), elevationMap.end());
    *firstMaxPeakIt += 1;

    return elevationMap;
}

int solve(const std::vector <int> &map){//O(n)
    int n = map.size();
    int res = 0;//result
    std::vector <int> l(n), r(n);//max values till ith position, l is for left, r is for right
    l[0] = map[0];
    r[n - 1] = map[n - 1];

    for (int i = 1 ; i < n ; i ++){
        l[i] = std::max(map[i], l[i - 1]);
    }

    for (int i = n - 2; i >= 0 ; i--){
        r[i] = std::max(map[i], r[i + 1]);
    }

    for (int i = 0 ; i < n ; i ++){
        res += std::min(l[i],r[i]) - map[i];
    }
    return res;    
}