#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector>
#include <algorithm>
#include <stdexcept>

template<class T>
T median(std::vector<T> v)
{
  typedef typename std::vector<T>::size_type vec_siz;

  
  vec_siz size = v.size();

  if (size == 0 ){
    throw std::domain_error("median of an empty vector");
  }

  std::sort(v.begin(), v.end());
  vec_siz mid = size / 2;

  return size % 2 == 0 ? (v[mid] + v[mid-1] / 2): v[mid];
}

#endif
