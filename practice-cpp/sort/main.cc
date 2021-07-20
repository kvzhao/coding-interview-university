
#include <ctime>

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

#include "sort_algorithm.hpp"
#include "helper.hpp"

int main(int argc, char *argv[]) {


    std::vector<int> arr;
    std::fstream file("../../random.txt");
    if (file.is_open()) {
	std::string line;
        while (getline(file, line)) {
            arr.emplace_back(std::stoi(line));
        }
        std::cout << "arr size = " << arr.size() << "\n";
    } else {
        std::cout << "can not open file\n";
        // TODO: Random integer
        // min + ( std::rand() % ( max - min + 1 ) )
    }

    auto ms = MergeSort();
    ms.sort(arr);

    // print
    if (is_sorted(arr)) {
        std::cout << "Merge Sort Passed\n";
    } else {
        for (auto v : arr) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(arr), std::end(arr), rng);

    auto qs = QuickSort();

    qs.sort(arr);

    // print
    if (is_sorted(arr)) {
        std::cout << "Quick Sort Passed\n";
    } else {
        for (auto v : arr) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }

    return 0;
}