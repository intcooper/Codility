/**
 * @file Nesting.cpp
 * @brief Determine whether a given string of parentheses (single type) is properly nested.
 *
 */

#include <stack>
#include <string>

int solution(std::string& S)
{
    std::stack<char> chars;

    for (const auto& c : S)
    {
        if (c == '(')
        {
            chars.push(c);
        }
        else
        {
            if (chars.empty())
                return 0;

            chars.pop();
        }
    }

    return chars.empty() ? 1 : 0;
}
