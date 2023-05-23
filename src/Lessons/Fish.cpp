/**
 * @file Fish.cpp
 * @brief N voracious fish are moving along a river. Calculate how many fish are alive.
 *
 */

#include <stack>
#include <vector>

int solution(const std::vector<int>& A, const std::vector<int>& B)
{
    const size_t N{A.size()};
    size_t remaining{N};
    std::stack<int> upstream_fish;

    for (size_t i = 0; i < N; ++i)
    {
        if (B[i] == 1)
        {
            upstream_fish.push(A[i]);
        }
        else
        {
            while (!upstream_fish.empty())
            {
                --remaining;

                if (upstream_fish.top() < A[i])
                {
                    upstream_fish.pop();
                }
                else
                {
                    break;
                }
            }
        }
    }

    return remaining;
}