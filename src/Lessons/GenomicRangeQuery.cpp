/**
 * @file GenomicRangeQuery.cpp
 * @brief Find the minimal nucleotide from a range of sequence DNA.
 *
 */

#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> solution(std::string& S, std::vector<int>& P, std::vector<int>& Q)
{
    std::vector<int> result;
    std::vector<std::vector<int>> count; // The count of each nucleotide up to the related element of S
    std::unordered_map<char, int> factors{{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

    count.emplace_back();
    count[0].assign(4, 0);
    count[0][factors[S[0]] - 1] = 1;

    for (size_t i = 1; i < S.size(); ++i)
    {
        count.emplace_back();
        count[i] = count[i - 1];
        const auto nucleotide_index = factors[S[i]] - 1;
        ++count[i][nucleotide_index];
    }

    for (size_t i = 0; i < P.size(); ++i)
    {
        const auto lowerBound = P[i];
        const auto upperBound = Q[i];

        for (size_t j = 0; j < count[i].size(); ++j)
        {
            auto lowerCount{0};
            if ((lowerBound > 0))
            {
                lowerCount = count[lowerBound - 1][j];
            }

            const auto nucleotide_count = count[upperBound][j] - lowerCount;

            if (nucleotide_count > 0)
            {
                result.push_back(j + 1);
                break;
            }
        }
    }

    return result;
}
