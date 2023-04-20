/**
 * @file ThreeLetters.cpp
 * @brief Given two integers A and B, return a string which contains A letters
 * "a" and B letters "b" with no three consecutive letters being the same.
 *
 * https://app.codility.com/programmers/trainings/5/three_letters/
 */

#include <string>

std::string solution(int A, int B) {
  std::string output;

  while (A > 0 || B > 0) {
    int nOfa{2};
    int nOfb{1};

    if (A < B) {
      nOfa = 1;
      nOfb = 2;
    }

    if (A < nOfa)
      nOfa = A;
    if (B < nOfb)
      nOfb = B;

    if ((output.empty() && (A > B)) || output.back() == 'b') {
      output.append(nOfa, 'a');
      output.append(nOfb, 'b');
    } else {
      output.append(nOfb, 'b');
      output.append(nOfa, 'a');
    }

    A -= nOfa;
    B -= nOfb;
  }

  return output;
}
