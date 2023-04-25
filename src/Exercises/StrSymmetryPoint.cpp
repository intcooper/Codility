/**
 * @file StrSymmetryPoint.cpp
 * @brief Find a symmetry point of a string, if any.
 *
 * https://app.codility.com/programmers/trainings/4/str_symmetry_point/
 */
#include <string>

int solution(std::string& S)
{
    if (S.size() == 0)
        return -1;

    if (S.size() == 1)
        return 0;

    if (S.size() % 2 == 0)
        return -1;

    int index = S.size() / 2;

    for (size_t i = 0; i < S.size() / 2; ++i)
    {
        if (*std::next(S.begin(), i) != *std::next(S.rbegin(), i))
        {
            return -1;
        }
    }

    return index;
}