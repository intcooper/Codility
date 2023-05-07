/**
 * @file CountDiv.cpp
 * @brief Compute number of integers divisible by k in range [a..b].
 *
 */

int solution(int A, int B, int K)
{
    return (B / K) - (A / K) + (A % K == 0 ? 1 : 0);
}
