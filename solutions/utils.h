#include "pch.h"

namespace utils {

template <typename T>
bool set_euqal(const std::vector<T> &v1, const std::vector<T> &v2) {
  std::vector<T> c1 = v1;
  std::vector<T> c2 = v2;

  if (std::unique(c1.begin(), c1.end()) != c1.end()) {
    throw std::runtime_error("v1 not unique");
  }

  if (std::unique(c2.begin(), c2.end()) != c2.end()) {
    throw std::runtime_error("v2 not unique");
  }

  std::sort(copy1.begin(), copy1.end());
  std::sort(copy2.begin(), copy2.end());

  return copy1 == copy2;
}

}
