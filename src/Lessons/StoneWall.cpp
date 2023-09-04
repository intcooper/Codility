/**
 * @file StoneWall.cpp
 * @brief Cover "Manhattan skyline" using the minimum number of rectangles.
 *
 */

#include <stack>
#include <vector>

int solution(const std::vector<int>& H)
{
    std::stack<int> blocks;
    int count{0};

    for (size_t i = 0; i < H.size(); ++i)
    {
        while (!blocks.empty() && (blocks.top() > H[i]))
        {
            blocks.pop();
        }

        if (blocks.empty() || (blocks.top() < H[i]))
        {
            blocks.push(H[i]);
            ++count;
        }
    }

    return count;
}
