#pragma once

#include "list_node.hpp"
#include <memory>

using std::shared_ptr;


template <typename T>
class LinkedList {
public:
LinkedList();

private:
shared_ptr<ListNode<T>> head_;
};