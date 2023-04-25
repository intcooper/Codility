/**
 * @file PermMissingElem.cpp
 * @brief Find the missing element in a given permutation.
 *
 */

#include <algorithm>
#include <vector>

int solution(std::vector<int>& A)
{
    if (A.empty())
    {
        return 1;
    }

    std::sort(A.begin(), A.end());

    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] != static_cast<int>(i + 1))
        {
            return i + 1;
        }
    }

    return A.size() + 1;
}
