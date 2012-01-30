#ifndef VEC_H
#define VEC_H


#include <algorithm>
#include <cstddef>
#include <memory>

using std::max;

template<class T>
class Vec
{
 public:
  
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef size_t size_type;
  //wrong typedef value_type T;
  typedef T value_type;

  Vec() { create();}
  explicit Vec(size_type n, const T& val = T()} { create(n, val);}
  Vec(const Vec& v) { create(v.begin(), v.end()); } 
  //how about copy(v.begin(), v.end(), this) ?

  Vec& operator=(Vec& rhs);

  ~Vec() { uncreate(); }

  T& operator[](size_type i) { return data[i]; }
  const T& operator[](size_type i) const  { return data[i]; }

  void push_back(const T& val) //void push_back(value_type v)
  {
    if ( avail == limit){
      grow();
    }
    unchecked_append(val);
  } 

  size_type size() const { return avail - data; }

  iterator begin() { return data; }
  const iterator begin() const { return data; }

  iterator end() { return avail; }
  const iterator end() const { return avail; }

 private:
  //T* data;
  //T* limit;
  iterator data;
  iterator avai;
  iterator limit;
 
  // facilities for memory allocation
  allocator<T> alloc; //object to hold memory allocation

  //allocate and initialize the underlying array
  void create();
  void create(size_type, const T&);
  void create(const_iterator, const_iterator);

  //destroy the elements in the array and free the memory
  void uncreate();

  // support function for push_back
  void grow();
  void unchecked_append(const T&);
};

template <class T>
void Vec<T>::create()
{
  data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val)
{
  data = alloc.allocate(n);
  limit = avail = data + n;
  uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
  data = alloc.allocate(j - i);
  limit = avail = uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate()
{
  if(data){
    iterator it = avail;
    while ( it != data){
      alloc.destroy(--it);
    }
    alloc.deallocate(data, limit - data);
  }
  data = avail = limit = 0;
}

template <class T>
void Vec<T>::grow()
{
  size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
  iterator new_data = alloc.allocate(new_size);
  iterator new_avail = uninitialized_copy(data, avail, new_data);

  uncreate();

  data = new_data;
  avail = new_avail;
  limit = data + new_size;
}

template <class T>
void Vec<T>::unckecked_append(const T& val)
{
  alloc.construct(avail++, val);
}

#endif //why #endif is not here in the sample code?
