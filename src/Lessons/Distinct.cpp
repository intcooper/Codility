/**
 * @file Distinct.cpp
 * @brief Compute number of distinct values in an array.
 *
 */

#include <set>

int solution(vector<int>& A)
{
    std::set<int> distinct;

    for (const auto& i : A)
    {
        distinct.insert(i);
    }

    return distinct.size();
}