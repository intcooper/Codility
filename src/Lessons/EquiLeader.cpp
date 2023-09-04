/**
 * @file EquiLeader.cpp
 * @brief Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are
 * the same.
 *
 */

#include <vector>

int solution(const std::vector<int>& A)
{
    size_t size{0};
    int value{-1};

    for (size_t i = 0; i < A.size(); ++i)
    {
        if (size == 0)
        {
            ++size;
            value = A[i];
        }
        else
        {
            if (A[i] != value)
            {
                --size;
            }
            else
            {
                ++size;
            }
        }
    }

    if (size == 0)
        return 0; // no candidates for equi-leader

    size_t count{0};

    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] == value)
            ++count;
    }

    // knowing how many instance of the leader are in the vector,
    // the number of instances in the sequences on the left and right of
    // any index can be calculated by subtraction.
    // Verifying the sequences is trivial as it requires depends only on the
    // number of elements and the number of leader instances.
    size_t equileaders{0};
    size_t numOfLeftLeads{0};
    size_t numOfRightLeads{0};

    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] == value)
            ++numOfLeftLeads;

        numOfRightLeads = count - numOfLeftLeads;

        if ((numOfLeftLeads * 2 > (i + 1)) && (numOfRightLeads * 2 > A.size() - (i + 1)))
        {
            ++equileaders;
        }
    }

    return equileaders;
}
