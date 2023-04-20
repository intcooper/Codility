/**
 * @brief ParityDegree.cpp
 *
 * Find the highest power of 2 that divides N. 
 * 
 * https://app.codility.com/programmers/trainings/5/parity_degree/
 */

int solution(int N) {
  int K{30};
  int div{1 << K};

  while (div > N) {
    --K;
    div >>= 1;
  }

  while (K > 0) {
    if (N % div == 0) {
      return K;
    }

    --K;
    div >>= 1;
  }

  return 0;
}