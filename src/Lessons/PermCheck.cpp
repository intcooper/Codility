/**
 * @file PermCheck.cpp
 * @brief Check whether array A is a permutation.
 *
 */
#include <vector>

int solution(std::vector<int>& A)
{
    const int N = static_cast<int>(A.size());
    std::vector<int> count(N + 1, 0);

    for (int i = 0; i < N; ++i)
    {
        if (A[i] > N)
        {
            return 0;
        }

        if (count[A[i]] != 0)
        {
            return 0;
        }

        ++count[A[i]];
    }

    for (size_t i = 1; i < count.size(); ++i)
    {
        if (count[i] == 0)
        {
            return 0;
        }
    }

    return 1;
}