/**
 * @file Brackets.cpp
 * @brief Determine whether a given string of parentheses (multiple types) is properly nested.
 *
 */

#include <string>
#include <stack>

int solution(const std::string& S)
{
    std::stack<char> chars;

    for (const auto& c : S)
    {
        if ((c == '(') || (c == '[') || (c == '{'))
        {
            chars.push(c);
        }
        else
        {
            if (chars.empty())
            {
                return 0;
            }

            if (((c == ')') && (chars.top() != '(')) || ((c == ']') && (chars.top() != '[')) ||
                ((c == '}') && (chars.top() != '{')))
            {
                return 0;
            }

            chars.pop();
        }
    }

    if (chars.empty())
    {
        return 1;
    }

    return 0;
}
