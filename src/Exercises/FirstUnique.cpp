/**
 * @file FirstUnique.cpp
 * @brief Find the first unique number in a given sequence. 
 *
 * https://app.codility.com/programmers/trainings/4/first_unique/
 */

#include <limits>
#include <map>
#include <vector>

struct Element {
  size_t minIndex;
  uint32_t count;
};

int solution(std::vector<int> &A) {
  const auto N = A.size();

  std::map<int, Element> distinct_count; // [value, [minindex, count]]

  for (size_t i = 0; i < N; ++i) {
    if (!distinct_count.contains(A[i])) {
      distinct_count.insert({A[i], {i, 1}});
    } else {
      ++distinct_count[A[i]].count;
    }
  }

  size_t minIndex{std::numeric_limits<int>::max()};
  int unique{-1};

  for (const auto d : distinct_count) {
    const auto &el = d.second;

    if (el.count == 1) {
      if (el.minIndex < minIndex) {
        unique = d.first;
        minIndex = d.second.minIndex;
      }
    }
  }

  return unique;
}