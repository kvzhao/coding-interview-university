#include "IVector.hpp"

#include <stdexcept>

using namespace CI;

IVector::IVector(int capacity) : size_(0) {

  if (capacity < 0) {
    // TODO assert error
  }

  int true_capacity = determin_capacity(capacity);
  capacity_ = true_capacity;

  // allocate memory
  data_ = std::unique_ptr<int []> (new int[true_capacity]);

}

IVector::~IVector() {

}


void IVector::push(int item) {


  // increment size
  // allocate more space if out-of-range
  // aiisgn

  data_[size_] = item;
  ++size_;
}

int IVector::at(int index) const {

  if (index >= size_ or index < 0) {
    throw std::invalid_argument("index is out-of-range");
  }

  return data_[index];
}


bool IVector::is_empty() const {
  return size_ == 0;
}

int IVector::get_size() const {
  return size_;
}

int IVector::get_capacity() const {
  return capacity_;
}

int IVector::determin_capacity (int capacity) {
  int true_capacity = CI::kMinCapacity;

  while (true_capacity / kGrowthFactor < capacity) {
    true_capacity *= kGrowthFactor;
  }

  return true_capacity;
}

void IVector::resize_capacity(int new_size) {

}