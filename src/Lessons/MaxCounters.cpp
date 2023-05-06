/**
 * @file MaxCounters.cpp
 * @brief Calculate the values of counters after applying all alternating operations: increase counter by 1; set value of all
 * counters to current maximum.
 *
 */

#include <algorithm>
#include <unordered_set>
#include <vector>

std::vector<int> solution(int N, std::vector<int>& A)
{
    std::vector<int> counters(N, 0);
    std::unordered_set<int> set;
    int max{0};
    int last_max{0};

    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] <= N)
        {
            if (!set.contains(A[i]))
            {
                counters[A[i] - 1] = last_max;
                set.insert(A[i]);
            }

            ++counters[A[i] - 1];
            max = std::max(max, counters[A[i] - 1]);
        }
        else
        {
            last_max = max;
            counters[A[i] - 1] = max;
            set.clear();
        }
    }

    if (last_max > 0)
    {
        for (int i = 0; i < N; ++i)
        {
            if (!set.contains(i + 1))
                counters[i] = last_max;
        }
    }

    return counters;
}