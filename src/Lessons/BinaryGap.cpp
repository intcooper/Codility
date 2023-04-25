/**
 * @file BinaryGap.cpp
 * @brief Find longest sequence of zeros in binary representation of an integer.
 */

int solution(int N)
{
    bool start{false};
    int count{0};
    int maxCount{0};

    while (N > 0)
    {
        if ((N & 1) == 1)
        {
            if (!start)
            {
                start = true;
            }
            else
            {
                maxCount = std::max(maxCount, count);
                count = 0;
            }
        }
        else
        {
            if (start)
                ++count;
        }

        N >>= 1;
    }

    return maxCount;
}