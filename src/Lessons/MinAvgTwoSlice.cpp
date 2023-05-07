/**
 * @file MinAvgTwoSlice.cpp
 * @brief Find the minimal average of any slice containing at least two elements.
 * @remarks The solution involves knowledge of a particular property of the averages (arithmetic mean) for which no average of 4 or
 * more integer can be smaller than the average of 2 or 3 integers of the same set.
 * Therefore, the below algorithm only calculates the average of all the 2- and 3- slices.
 */
#include <limits>
#include <vector>

int solution(std::vector<int>& A)
{
    float minAvg{std::numeric_limits<float>::max()};
    int minIndex{-1};

    for (size_t n = 2; n <= 3; ++n)
    {
        const auto offset = n - 1;

        for (size_t i = offset; i < A.size(); ++i)
        {
            int sum{0};
            for (size_t k = 0; k < n; ++k)
            {
                sum += A[i - k];
            }

            const float avg = static_cast<float>(sum) / n;

            if (minAvg > avg)
            {
                minAvg = avg;
                minIndex = i - offset;
            }
        }
    }

    return minIndex;
}