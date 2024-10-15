#include <algorithm>
#include <iostream>
#include <string>

class DifferentStrings {
 private:
  int rec(std::string A, std::string B, int start, int min) {
    int result = 0;
    int aSize = A.size();
    int bSize = B.size();

    if (start + aSize > bSize) {
      return min;
    }

    std::string newB = B.substr(start, start + aSize);

    for (int i = 0; i < aSize; i++) {
      if (A[i] != newB[i]) {
        result++;
      }
    }

    int newMin = std::min(result, min);

    return rec(A, B, start + 1, newMin);
  }

 public:
  int minimize(std::string A, std::string B) {
    int result = 0;
    int aSize = A.size();
    int bSize = B.size();
    if (aSize == bSize) {
      for (int i = 0; i < aSize; i++) {
        if (A[i] != B[i]) {
          result++;
        }
      }
    } else {
      result = rec(A, B, 0, INT_MAX);
    }

    return result;
  }
};