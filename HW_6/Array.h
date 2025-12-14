#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <stdexcept>

template <class T, int size>
class Array {
 private:
  T array_[size];

 public:
  Array() : array_{} {}

  explicit Array(const T* b) {
    if (b == nullptr) {
      for (int i = 0; i < size; ++i) {
        array_[i] = T();
      }
      return;
    }
    for (int i = 0; i < size; ++i) {
      array_[i] = b[i];
    }
  }

  void Show() const {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
      std::cout << array_[i] << (i < size - 1 ? ", " : "");
    }
    std::cout << "]";
  }

  T Minimum(const Array<T, size>&) const {
    if (size <= 0) {
      throw std::runtime_error("Array is empty. Cannot find minimum.");
    }

    T min_val = array_[0];

    for (int i = 1; i < size; ++i) {
      if (array_[i] < min_val) {
        min_val = min_val;
      }
    }
    return min_val;
  }
};

#endif
