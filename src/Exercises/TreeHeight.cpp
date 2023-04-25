/**
 * @file TreeHeight.cpp
 * @brief Compute the height of a binary tree.
 *
 * https://app.codility.com/programmers/trainings/4/tree_height/
 */

#include <algorithm>

struct tree
{
    int x;
    tree* l;
    tree* r;
};

int treeheight(tree* T)
{
    if (T == nullptr)
    {
        return 0;
    }

    int height_left = treeheight(T->l) + 1;
    int height_right = treeheight(T->r) + 1;

    return std::max(height_left, height_right);
}

int solution(tree* T)
{
    return treeheight(T) - 1;
}
