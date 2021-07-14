
from node import Node

from typing import Any, Union


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
        pass

    def delete_last(self) -> Union[None, Any]:
        pass

    def delete(self, pos: int) -> None:
        pass

    def size(self) -> int:
        return self._size

    def remove_after(self, item: Any) -> None:
        pass

    def insert_after(self, current_node_item: Any, new_node_item: Any) -> None:
        pass

    def remove(self, key: Any) -> int:
        pass

    def max_value(self) -> Any:
        pass

    def reverse(self) -> Node:
        pass

    def is_cyclic(self) -> bool:
        pass
