/**
 * @file OddOccurrencesInArray.cpp
 * @brief Find value that occurs in odd number of elements.
 *
 */

#include <ranges>
#include <stdexcept>
#include <vector>

int solution(std::vector<int>& A)
{
    const auto N = A.size();

    if (N == 1)
    {
        return A[0];
    }

    std::ranges::sort(A);
    size_t count{0};

    for (size_t i = 0; i < N - 1; ++i)
    {
        ++count;
        if (A[i] != A[i + 1])
        {
            if (count % 2 == 1)
            {
                return A[i];
            }

            count = 0;
        }
    }

    ++count;

    if (count % 2 == 1)
    {
        return A[N - 1];
    }

    throw std::logic_error{"assumptions not met!"};
}