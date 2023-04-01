#include <iostream>
#include <numeric>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>

uint32_t generate(uint32_t n)
{
    std::vector<uint32_t> numbers(n);
    std::iota(numbers.begin(), numbers.end(), 1);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, n - 1);
    uint32_t random_index = distribution(rng);

    numbers.erase(numbers.begin() + random_index);
    std::shuffle(numbers.begin(), numbers.end(), rng);

    std::ofstream file("random_1_" + std::to_string(n) + ".txt");

    for (auto &number : numbers)
        file << number << std::endl;

    return random_index + 1;
}

int main()
{
    generate(15);
    return 0;
}