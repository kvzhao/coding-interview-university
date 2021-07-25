#pragma once

#include <memory>

// namespace of coding interview
namespace CI {

namespace {
static const int kMinCapacity = 16;
static const int kGrowthFactor = 2;
}

template <typename T>
class Vector {

private:

int size_  = 0;
std::unique_ptr<T *> data_; 
};

// Implement a vector (mutable array with automatic resizing)
// Integer Vector
class IVector {
public:
	IVector(int capacity);

  // TODO: copy constructor

  ~IVector();

  void push(int item);

  int at(int index) const;

  int get_capacity() const;
  int get_size() const;
  bool is_empty() const;

private:
  int capacity_{kMinCapacity};

  int size_{0};

  std::unique_ptr<int []> data_ = nullptr;

  int determin_capacity(int cap);

  void resize_capacity(int new_size);

  void increase_capacity();
  void decrease_capacity();

};

}