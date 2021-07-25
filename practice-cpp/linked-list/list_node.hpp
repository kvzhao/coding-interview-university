
#pragma once

#include <memory>
using std::shared_ptr;

template<typename T>
struct ListNode {

ListNode(T data = {}, shared_ptr<ListNode<T>> next = nullptr)
	: data_(data), next_(next) {}

shared_ptr<ListNode<T>> next_;
T data_;

};