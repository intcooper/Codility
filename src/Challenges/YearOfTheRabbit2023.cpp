/**
 * @file YearOfTheRabbit2023.cpp
 * @brief Solution to the _Dinner_ task published as part of the Codility Year
 * of The Rabbit challenge.
 * https://app.codility.com/programmers/challenges/year_of_the_rabbit_2023/
 *
 * Award: https://app.codility.com/cert/view/certUXNPDV-2PYXHT8NDTWP3QWE/
 * Assessment: https://app.codility.com/cert/view/certUXNPDV-2PYXHT8NDTWP3QWE/details/
 *
 * There are N people sitting at a round table, having dinner.
 * They are numbered from 0 to N-1 in clockwise order. Initially, each person
 * has a dish on the table in front of them. Person number K does not like the
 * taste of A[K], but has a dish of taste B[K]. We want every person to have a
 * dish of a taste that they do not dislike, i.e. A[K] ≠ B[K] for each K from 0
 * to N-1.
 *
 * In order to achieve this, you can rotate the whole table clockwise by one
 * position any number of times. Rotating the table corresponds to moving the
 * last element of B to the beginning. For example, given A = [3, 6, 4, 5] and B
 * = [2, 6, 3, 5], if we rotate the table once, we would obtain B = [5, 2, 6, 3].
 *
 * Find the minimum number of table rotations that need to be performed in order
 * to satisfy every person.
 *
 * Write a function:
 * int solution(vector<int> &A, vector<int> &B);
 *
 * that, given arrays A and B, both consisting of N integers, representing
 * tastes that people do not like and the taste of their dishes, respectively,
 * returns the minimum number of table rotations required so that every person
 * has a dish whose taste they do not dislike.
 * In particular, if no rotations are needed, the function should return 0. If
 * fulfilling the above condition is impossible, the function should return -1.
 */

#include <vector>

int solution(std::vector<int>& A, std::vector<int>& B)
{
    for (size_t rotations{0}; rotations < A.size(); ++rotations)
    {
        size_t i = 0;

        for (; i < A.size(); ++i)
        {
            if (A[i] == B[i])
            {
                break;
            }
        }

        if (i == B.size())
        {
            return rotations;
        }

        const auto back = B.back();
        B.insert(B.begin(), back);
        B.pop_back();
    }

    return -1;
}
