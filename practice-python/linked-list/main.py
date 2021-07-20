
from linked_list import LinkedList


def main():
    ll = LinkedList()

    for n in reversed(range(10, 100, 10)):
        ll.append(n)

    print("ll = ")
    ll.print_list()

    last_one = ll.delete_last()
    print("delete last val", last_one)
    ll.print_list()

    first_one = ll.delete_first()
    print("delete first val", first_one)
    ll.print_list()

    ll.delete(3)
    print("delete 3")
    ll.print_list()

    print("remove after 60")
    ll.remove_after(60)
    ll.print_list()

    print("remove after 40")
    ll.remove_after(40)
    ll.print_list()

    print("insert after 40")
    ll.insert_after(40, 41)
    ll.print_list()

    print("max value of list", ll.max_value())

    ll.reverse()
    print("reverse")
    ll.print_list()


if __name__ == "__main__":
    main()
