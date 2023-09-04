/**
 * @file Dominator.cpp
 * @brief Find an index of an array such that its value occurs at more than half of indices in the array.
 *
 */

#include <limits>
#include <vector>

int solution(const std::vector<int>& A)
{
    size_t size{0};
    int value{-1};

    for (size_t i = 0; i < A.size(); ++i)
    {
        if (size == 0)
        {
            value = A[i];
            ++size;
        }
        else
        {
            if (A[i] != value)
            {
                --size;
            }
            else
            {
                ++size;
            }
        }
    }

    if (size == 0)
        return -1;

    size_t idx{std::numeric_limits<size_t>::max()};
    size_t count{0};

    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] == value)
        {
            ++count;
            idx = i;
        }
    }

    return ((count * 2) > A.size()) ? idx : -1;
}
