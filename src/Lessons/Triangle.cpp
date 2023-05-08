/**
 * @file Triangle.cpp
 * @brief Determine whether a triangle can be built from a given set of edges.
 *
 */

#include <algorithm>
#include <vector>

int solution(std::vector<int>& A)
{
    const size_t N = A.size();

    if (N < 3)
        return 0;

    std::sort(A.begin(), A.end());

    for (size_t i = 0; i < (N - 2); ++i)
    {
        const auto a = static_cast<int64_t>(A[i]);
        const auto b = static_cast<int64_t>(A[i + 1]);
        const auto c = static_cast<int64_t>(A[i + 2]);

        if ((a + b) > c)
        {
            return 1;
        }
    }

    return 0;
}
