/**
 * @file CountFactors.cpp
 * @brief Count factors of given number n.
 *
 */

#include <stdint.h>

int solution(int N)
{
    uint64_t factors{0};
    uint64_t i{1};
    uint64_t n{static_cast<uint64_t>(N)};

    while ((i * i) < n)
    {
        if (n % i == 0)
        {
            factors += 2;
        }

        ++i;
    }

    if ((i * i) == n)
        ++factors;

    return factors;
}