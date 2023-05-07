/**
 * @file MissingInteger.cpp
 * @brief Find the smallest positive integer that does not occur in a given sequence. 
 * 
 */

#include <stdexcept>
#include <unordered_set>

int solution(std::vector<int> &A) {
    std::unordered_set<int> distinct_positives;

    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] > 0)
        {
            distinct_positives.insert(A[i]);
        }
    }

    constexpr int MaxElement{1'000'000};

    for (size_t i = 1; i < MaxElement; ++i)
    {
        if (!distinct_positives.contains(i))
        {
            return i;
        }
    }

    throw std::logic_error("logical error!");
}