#include <iostream>
#include<cmath>
#include <vector>
#include <cassert>
#include <array>
#include <algorithm>

// =========================================================================================
// EXERCISE
// =========================================================================================
// Buffers can be used to store data temporarily while it is being processed in some way.
// For example, you might use a buffer to store data that is being read from a stream 
// and detect some patterns.
//  
// You should implement:
//  1. a Buffer data structure with including the required interfaces
//  2. a function to detect a symmetric buffer
//
// =========================================================================================
// Your implementation - CODE HERE 
// =========================================================================================
template <typename T, size_t N>
class Buffer {
private:
    T data_[N] = {};
    size_t size_ = {};

public:
  // Constructor
  Buffer(std::initializer_list<T> init):size_{std::min(init.size(),N)} {
    std::move(std::begin(init), std::next(std::begin(init), size_), data_);
  }

  // Destructor

  // operators 
  auto& operator[] (int index) const {
    return data_[index];
  }
  auto& operator[] (int index) {
     return data_[index];
  }

  // methods
  bool full() const {
    return (size_ == N);
  }

  bool push_back(T data) {
    if (full()) return false;
    data_[size_++] = data;
    return true;
  }

  void clear() {
    size_ = 0;
  }

  auto size() const {
    return size_;
  }
 
  // iterators
  auto begin() const { return &data_[0]; }
  auto end() const { return &data_[size_]; }
  auto rbegin() const { return std::make_reverse_iterator(end()); }
  auto rend() const { return std::make_reverse_iterator(begin()); }
  
};

template<typename T>
bool symmetric(const T& buffer) {
  return std::equal(
    std::begin(buffer), 
    std::next(std::begin(buffer),buffer.size()>>1), 
    std::rbegin(buffer));
}

// =========================================================================================
// Execution Process - DO NOT TOUCH 
// =========================================================================================

// =========================================================================================
// END
// =========================================================================================