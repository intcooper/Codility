/**
 * @file PassingCars.cpp
 * @brief Count the number of passing cars on the road.
 *
 */
#include <vector>
#include <algorithm>

int solution(std::vector<int>& A)
{
    const size_t N = A.size();
    uint32_t pairs{0};
    std::vector<int> sums(N, 0);

    sums[0] = A[N - 1];

    for (size_t i = 1; i < N; ++i)
    {
        sums[i] = A[N - 1 - i] + sums[i - 1];
    }

    constexpr int MaxPairs{1'000'000'000};

    for (size_t i = 0; i < N; ++i)
    {
        if (A[N - 1 - i] == 0)
        {
            pairs += sums[i];

            if (pairs > MaxPairs)
            {
                return -1;
            }
        }
    }

    return pairs;
}