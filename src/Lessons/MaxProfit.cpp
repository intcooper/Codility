/**
 * @file MaxProfit.cpp
 * @brief Given a log of stock prices compute the maximum possible earning.
 * 
 */

#include <vector>

int solution(const std::vector<int> &A) {
    std::vector<int> diffs(A.size(), 0);

    for (size_t i = 1; i < A.size(); ++i)
    {
        diffs[i] = A[i] - A[i - 1];
    }

    int current_profit{0};
    int highest_profit{0};

    for (size_t i = 0; i < diffs.size(); ++i)
    {
        current_profit = std::max(0, current_profit + diffs[i]);
        highest_profit = std::max(highest_profit, current_profit);
    }

    return highest_profit;
}
