#pragma once
#include <cstddef> // for size_t
#include <algorithm>

// A min_bucket of size n stores the smallest (at most) n
// objects ever inserted within.

template <typename T>
class min_bucket {
public:
  min_bucket(size_t);
  ~min_bucket();
  void insert(const T&);
  int operator[](size_t);
  // make copy constructor and copy assignment unavailable
  min_bucket(const min_bucket&) = delete;
  min_bucket& operator=(const min_bucket&) = delete;
private:
  const size_t size; // must be initialized
  int count; // number of objects stored
  int* nums = nullptr;
};

#include "min_bucket.h"
#include <exception>

template <typename T>
min_bucket<T>::min_bucket(size_t n): size(n), count(0)
{
  nums = new int [n+1];
  if (nums == nullptr) throw std::exception();
}

template <typename T>
min_bucket<T>::~min_bucket()
{
  delete [] nums;
}

template <typename T>
void min_bucket<T>::insert(const T& x)
{
  if (count < size) {
    nums[count] = x;
  }
  else { // full
    nums[size] = x; // place x at the end
  }
  int i = count-1;
  while (i >= 0  && nums[i] > nums[i+1]) {
    std::swap(nums[i], nums[i+1]);
    i--;
  }
  if (count < size) count++;
}

template <typename T>
int min_bucket<T>::operator[](size_t n)
{
  if (n >= size) throw std::exception();
  return nums[n];
}
