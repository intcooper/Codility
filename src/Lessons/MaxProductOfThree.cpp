/**
 * @file MaxProductOfThree.cpp
 * @brief Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).
 *
 */

#include <algorithm>
#include <vector>

int solution(std::vector<int>& A)
{
    const size_t N{A.size()};
    std::sort(A.begin(), A.end());

    int product{A[N - 1] * A[N - 2] * A[N - 3]};
    product = std::max(product, A[0] * A[1] * A[N - 1]);
    product = std::max(product, A[0] * A[N - 1] * A[N - 2]);

    return product;
}
