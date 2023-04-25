/**
 * @file WholeSquareCount.cpp
 * @brief A solution of the _WholeSquareCount_ problem.
 *
 * An integer P is a whole square if it is a square of some integer Q;
 * i.e. if P = Q^2.
 * Write a function:
 *   int solution(int A, int B);
 * that, given two integers A and B, returns the number of whole squares within
 * the interval [A..B] (both ends included).
 * For example, given A = 4 and B = 17, the function should return 3, because
 * there are three squares of integers in the interval [4..17], namely 4 = 2^2,
 * 9 = 3^2 and 16 = 4^2. Assume that:
 * - A and B are integers within the range [−2,147,483,648..2,147,483,647];
 * - A <= B.
 * Complexity:
 * - expected worst-case time complexity is O(sqrt(abs(B)));
 * - expected worst-case space complexity is O(1).
 */

int solution(int A, int B)
{
    if (B < 0)
        return 0;

    int count{0};
    int q{0};
    int square{0};

    while (square <= B)
    {
        if (square >= A)
            ++count;

        ++q;
        square = q * q;
    }
}