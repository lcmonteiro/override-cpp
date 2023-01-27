#include <gtest/gtest.h>
#include "buffer.hpp"

template<typename T>
void debug(const char* msg, const T& container) {
    std::cout << msg << " => ";
    for (auto data: container)
        std::cout << data << " ";
    std::cout << std::endl;
}

/// Buffer 
/// @brief general test
TEST(override, buffer_test) {
  auto stream = std::vector<int>{1,2,3,4,5,4,7,8,9,0};
  auto expect = std::vector<int>{4,5,4};
  auto result = std::vector<int>{};
  auto buffer = Buffer<int, 3>{};
  for (auto& data : stream) {
    debug("buffer", buffer);
    if (buffer.full()) {
      if(symmetric(buffer)) {
        std::copy(
          std::cbegin(buffer), 
          std::cend(buffer),
          std::back_inserter(result));
      }
      buffer.clear();
    }
    buffer.push_back(data);
  }
  debug("result", result);
  assert(("mismatch", (result==expect)));
}

TEST(override, buffer_test_1) {
  auto buffer = Buffer<int, 3>{};
  const auto cbuffer = Buffer<int, 3>{1,2,3,4,5};
  debug("cbuffer", cbuffer);
  
  auto val = cbuffer[0];
  buffer.push_back(1);
  //buffer[0] = 2;
  debug("buffer", buffer);
}
