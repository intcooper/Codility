/**
 * @file TapeEquilibrium.cpp
 * @brief Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.
 *
 */

#include <vector>

int solution(std::vector<int>& A)
{
    int diff{0};

    int sumPart1{A[0]};
    int sumPart2{0};

    for (size_t i = 1; i < A.size(); ++i)
    {
        sumPart2 += A[i];
    }

    diff = std::abs(sumPart1 - sumPart2);

    if (A.size() == 2)
    {
        return diff;
    }

    for (size_t i = 1; i < A.size() - 1; ++i)
    {
        sumPart1 += A[i];
        sumPart2 -= A[i];

        diff = std::min(std::abs(sumPart1 - sumPart2), diff);
    }

    return diff;
}