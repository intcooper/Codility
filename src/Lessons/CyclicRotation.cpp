/**
 * @file CyclicRotation.cpp
 * @brief Rotate an array to the right by a given number of steps.
 */

#include <vector>

std::vector<int> solution(std::vector<int>& A, int K)
{
    const auto N = static_cast<int>(A.size());

    if (N == 0)
    {
        return A;
    }

    const int offset = K % N;

    if (offset == 0)
    {
        return A;
    }

    std::vector<int> res;

    for (int i = N - offset; i < N; ++i)
    {
        res.push_back(A[i]);
    }

    for (int i = 0; i < N - offset; ++i)
    {
        res.push_back(A[i]);
    }

    return res;
}