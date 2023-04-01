#include <iostream>
#include <numeric>
#include <vector>
#include <random>

uint32_t generate(uint32_t n)
{
    std::vector<uint32_t> numbers(n);
    std::iota(numbers.begin(), numbers.end(), 1);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, n - 1);
    uint32_t random_index = distribution(rng);

    

}

int main()
{
    generate(15);
    return 0;
}