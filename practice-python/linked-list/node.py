
from typing import Any


class Node(object):
    def __init__(self, val: Any) -> None:
        self._val = val
        self._next = None

    @property
    def val(self) -> Any:
        return self._val

    @val.setter
    def val(self, value: Any) -> None:
        self._val = value

    @property
    def next_node(self) -> Any:
        return self._next

    @next_node.setter
    def next_node(self, node: Any) -> None:
        self._next = node
