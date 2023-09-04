/**
 * @file MaxDoubleSliceSum.cpp
 * @brief Find the maximal sum of any double slice.
 *
 */
#include <vector>

int solution(std::vector<int>& A)
{
    size_t N{A.size()};

    if (N <= 3)
        return 0;

    std::vector<int> sum_to(N, 0);
    std::vector<int> sum_from(N, 0);

    int max_sum{0};
    for (size_t i = 1; i < A.size(); ++i)
    {
        max_sum = std::max(0, max_sum + A[i]);
        sum_to[i] = max_sum;
    }

    max_sum = 0;
    for (int i = N - 2; i >= 0; --i)
    {
        max_sum = std::max(0, max_sum + A[i]);
        sum_from[i] = max_sum;
    }

    int max_slice{0};

    for (size_t i = 1; i < A.size() - 1; ++i)
    {
        max_slice = std::max(max_slice, sum_to[i - 1] + sum_from[i + 1]);
    }

    return max_slice;
}