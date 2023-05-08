/**
 * @file NumberOfDiscIntersections.cpp
 * @brief Compute the number of intersections in a sequence of discs.
 *
 */

#include <algorithm>
#include <vector>

struct Circle
{
    int64_t min;
    int64_t center;
    int64_t max;
};

int solution(std::vector<int>& A)
{
    std::vector<Circle> circles;

    for (size_t i = 0; i < A.size(); ++i)
    {
        circles.emplace_back(i - A[i], i, i + A[i]);
    }

    std::sort(circles.begin(), circles.end(), [](const auto a, const auto b) { return a.max > b.max; });

    constexpr uint32_t MaxIntersections{10'000'000};
    uint32_t intersections{0};

    for (size_t i = 0; i < circles.size(); ++i)
    {
        for (size_t j = i + 1; j < circles.size(); ++j)
        {
            if (circles[j].max < circles[i].min)
            {
                break;
            }

            ++intersections;

            if (intersections > MaxIntersections)
            {
                return -1;
            }
        }
    }

    return intersections;
}
