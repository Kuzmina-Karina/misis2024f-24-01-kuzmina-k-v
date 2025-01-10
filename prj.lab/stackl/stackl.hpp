#ifndef STACKL_STACKL_HPP_20241203
#define STACKL_STACKL_HPP_20241203

#include <cstddef>
#include <cstdint>
#include <iostream>

class StackL{
public:
  using T = std::uint8_t;
public:
  StackL() = default;
  StackL(const StackL& src);
  StackL(StackL&& src);
  ~StackL() = default;

  
  StackL& operator=(const StackL& src);
  StackL& operator=(StackL&& src);
  bool IsEmpty() const;
  void Pop();
  void Push(const T val);
  T& Top();
  void Clear();

private:
  struct Node {
    T val = T();
    Node* next = nullptr;
  };
  Node* head_ = nullptr;
};

#endif