/**
 * @file FrogRiverOne.cpp
 * @brief Find the earliest time when a frog can jump to the other side of a river.
 *
 */

#include <vector>

int solution(int X, std::vector<int>& A)
{
    constexpr int MaxElement{100'000};
    std::vector<int> count(MaxElement + 1, 0);
    int steps{X};
    int earliestTime{-1};

    for (size_t i = 0; i < A.size(); ++i)
    {
        if ((A[i] <= X) && (count[A[i]] == 0))
        {
            --steps;
            ++count[A[i]];
        }

        if (steps == 0)
        {
            earliestTime = i;
            break;
        }
    }

    return earliestTime;
}