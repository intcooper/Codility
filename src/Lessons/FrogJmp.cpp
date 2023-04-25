/**
 * @file FrogJmp.cpp
 * @brief Count minimal number of jumps from position X to Y.
 *
 */

int solution(int X, int Y, int D)
{
    int answer = (Y - X) / D;
    return X + (D * answer) >= Y ? answer : answer + 1;
}
