class Node(object):

    def __init__(self, data, next_node=None):
        
        self.__data = data
        self.__next = next_node

    @property
    def data(self):
        
        return self.__data

    @data.setter
    def data(self, data):
        
        self.__data = data

    @property
    def next_node(self):
        
        return self.__next

    @next_node.setter
    def next_node(self, next_node):
        
        self.__next = next_node


class SinglyLinkedList(object):
    
    def __init__(self):
        self.__head = None

    def find_by_value(self, value):
        
        node = self.__head
        while (node is not None) and (node.data != value):
            node = node.next_node
        return node

    def find_by_index(self, index):
        
        node = self.__head
        pos = 0
        while (node is not None) and (pos != index):
            node = node.next_node
            pos += 1
        return node

    def insert_to_head(self, value):
        
        node = Node(value)
        node.next_node = self.__head
        self.__head = node

    def insert_after(self, node, value):
        
        if node is None:  
            return

        new_node = Node(value)
        new_node.next_node = node.next
        node.next = new_node

    def insert_before(self, node, value):
        
        if (node is None) or (self.__head is None):  
            return

        if node == self.__head:  
            self.insert_to_head(value)
            return

        new_node = Node(value)
        pro = self.__head
        not_found = False  
        while pro.next_node != node:  
            if pro.next_node is None:  
                not_found = True
                break
            else:
                pro = pro.next_node
        if not not_found:
            pro.next_node = new_node
            new_node.next_node = node

    def delete_by_node(self, node):
        
        if self.__head is None:  
            return

        if node == self.__head:  
            self.__head = node.next_node
            return

        pro = self.__head
        not_found = False  
        while pro.next_node != node:
            if pro.next_node is None:  
                not_found = True
                break
            else:
                pro = pro.next_node
        if not not_found:
            pro.next_node = node.next_node

    def delete_by_value(self, value):
        if self.__head is None: 
            return

        if self.__head.data == value:  
            self.__head = self.__head.next_node

        pro = self.__head
        node = self.__head.next_node
        not_found = False
        while node.data != value:
            if node.next_node is None: 
                not_found = True
                break
            else:
                pro = node
                node = node.next_node
        if not_found is False:
            pro.next_node = node.next_node

    def delete_last_n_node(self, n):
        fast = self.__head
        slow = self.__head
        step = 0

        while step <= n:
            fast = fast.next_node
            step += 1

        while fast.next_node is not None:
            tmp = slow
            fast = fast.next_node
            slow = slow.next_node

        tmp.next_node = slow.next_node

    def find_mid_node(self):
        fast = self.__head
        slow = self.__head

        while fast.next_node is not None:
            fast = fast.next_node.next_node
            slow = slow.next_node

        return slow

    def create_node(self, value):
        return Node(value)

    def print_all(self):
        """打印当前链表所有节点数据."""
        pos = self.__head
        if pos is None:
            print("There is no data in the current linkedlist")
            return
        while pos.next_node is not None:
            print(str(pos.data) + " --> ", end="")
            pos = pos.next_node
        print(str(pos.data))

    def reversed_self(self):
        if self.__head is None or self.__head.next is None:  
            return

        pre = self.__head
        node = self.__head.next
        while node is not None:
            pre, node = self.__reversed_with_two_node(pre, node)

        self.__head.next = None
        self.__head = pre

    def __reversed_with_two_node(self, pre, node):
        tmp = node.next_node
        node.next_node = pre
        pre = node  
        node = tmp
        return pre, node

    def has_ring(self):
        fast = self.__head
        slow = self.__head

        while (fast.next_node is not None) and (fast is not None):
            fast = fast.next_node
            slow = slow.next_node
            if fast == slow:
                return True

        return False