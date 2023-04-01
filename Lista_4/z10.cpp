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

uint32_t find_missing_number(std::string file_name)
{
    std::ifstream input(file_name);
    uint32_t n = 1;
    uint32_t number = 0;
    uint32_t sum = 0;
    while(input >> number)
    {
        ++n;
        sum += number;
    }
    std::cout << ((1 + n) * n / 2) << "\n";
    return ((1 + n) * n / 2) - sum;
}

int main()
{
    uint32_t n = 1234567;
    uint32_t missing = generate(n);
    uint32_t found = find_missing_number("random_1_" + std::to_string(n) + ".txt");
    std::cout << missing << " " << found;
    return 0;
}