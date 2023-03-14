#
# Insertion Sort List
#
# Sort a singly linked list using insertion sort.
#
# Joel Rorseth
#

# Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None


def insertionSortList(head):

    if not head or not head.next:
        return head

    # Populate a new list, starting with dummy node for easy head replace
    new_list = ListNode(-1)
    cur = head

    while cur:

        new_element = ListNode(cur.val)
        cur = cur.next

        new_prev = new_list
        new_cur = new_list.next

        # Move ptrs so that new_prev < new_element < new_cur
        while new_cur:
            if new_element.val <= new_cur.val:
                break
            else:
                new_prev = new_cur
                new_cur = new_cur.next

        # New element should now be inserted between new_prev and new_cur
        new_prev.next = new_element
        new_element.next = new_cur

    return new_list.next







# Driver
def print_list(head):
    cur = head
    while cur:
        print(cur.val, end="->")
        cur = cur.next
    print("None")

n1 = ListNode(5)
n2 = ListNode(2)
n3 = ListNode(7)
n4 = ListNode(1)
n5 = ListNode(4)
n1.next = n2
n2.next = n3
n3.next = n4
n4.next = n5
print("Input:  ", end="")
print_list(n1)
print("Sorted: ", end="")
print_list(insertionSortList(n1))

