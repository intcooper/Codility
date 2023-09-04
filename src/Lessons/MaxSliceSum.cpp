/**
 * @file MaxSliceSum.cpp
 * @brief Find a maximum sum of a compact subsequence of array elements.
 *
 */
#include <vector>

int solution(const std::vector<int>& A)
{
    int highest_sum{A[0]};
    int current_sum{A[0]};

    for (size_t i = 1; i < A.size(); ++i)
    {
        current_sum = std::max(A[i], current_sum + A[i]);
        highest_sum = std::max(highest_sum, current_sum);
    }

    return highest_sum;
}
