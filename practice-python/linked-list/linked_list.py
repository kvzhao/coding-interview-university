
from node import Node

from typing import Any, Union

# TODO: Linked list merge sort


class LinkedList(object):

    def __init__(self) -> None:
        self._first = None
        self._size = 0

    def print_list(self) -> None:
        tmp = self._first

        while tmp:
            if not tmp.next_node:
                print(tmp.val)
            else:
                print(tmp.val, end=" ")
            tmp = tmp.next_node

    def append(self, val: Any) -> None:
        if not self._first:
            self._first = Node(val)
            self._size += 1
            return
        tmp = self._first
        while tmp.next_node:
            tmp = tmp.next_node
        tmp.next_node = Node(val)
        self._size += 1

    def find(self, val: Any) -> bool:
        tmp = self._first
        while tmp:
            if tmp.val == val:
                return True
            tmp = tmp.next_node
        return False

    def delete_first(self) -> Union[None, Any]:
        tmp = self._first
        if not tmp:
            return None
        if not tmp.next_node:
            deleted_val = tmp.val
            self._first = None
            self._size -= 1
            return deleted_val

        deleted_val = tmp.val
        self._first = tmp.next_node
        self._size -= 1
        return deleted_val

    def delete_last(self) -> Union[None, Any]:
        tmp = self._first
        if not tmp:
            return None
        # only one node
        if not tmp.next_node.next_node:
            deleted_val = tmp.val
            self._first = None
            self._size -= 1
            return deleted_val
        # to the n-1 node
        while tmp.next_node.next_node:
            tmp = tmp.next_node
        deleted_val = tmp.next_node.val
        tmp.next_node = None
        self._size -= 1
        return deleted_val

    def delete(self, pos: int) -> None:
        if pos > self._size:
            return

        if pos == 1:
            self._first = None
            self._size -= 1
            return

        tmp = self._first
        count = 1

        # to previous
        while count != pos - 1:
            tmp = tmp.next_node
            count += 1
        # a -> b -> c -> d
        target_node = tmp.next_node
        tmp.next_node = tmp.next_node.next_node
        target_node.next_node = None
        self._size -= 1

    def size(self) -> int:
        return self._size

    def remove_after(self, item: Any) -> None:
        tmp = self._first
        while tmp.next_node:
            if tmp.val == item:
                # remove all list
                tmp.next_node = tmp.next_node.next_node
                self._size -= 1
                break
            tmp = tmp.next_node

    def insert_after(self, current_node_item: Any, new_node_item: Any) -> None:
        tmp = self._first
        while tmp:
            if tmp.val == current_node_item:
                old_next_node = tmp.next_node
                tmp.next_node = Node(new_node_item)
                tmp.next_node.next_node = old_next_node
                self._size += 1
                break
            tmp = tmp.next_node

    def remove(self, key: Any) -> int:
        # remove all keys in list
        pass

    def max_value(self) -> Any:
        tmp = self._first
        max_value = None
        while tmp:
            if max_value is None:
                max_value = tmp.val
            if tmp.val > max_value:
                max_value = tmp.val
            tmp = tmp.next_node
        return max_value

    def reverse(self) -> Node:
        first = self._first
        reversed_node = None

        while first:
            second = first.next_node
            first.next_node = reversed_node
            reversed_node = first
            first = second
        self._first = reversed_node

    def is_cyclic(self) -> bool:
        if not self._first:
            return False

        fast, slow = self._first
        while fast and fast.next_node:
            fast = fast.next_node.next_node
            slow = slow.next_node

            if fast == slow:
                return True
        return False
