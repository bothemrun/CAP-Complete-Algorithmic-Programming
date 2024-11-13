class Node:
    def __init__(self, key=(-1), value=(-1)):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0

        # dummy nodes
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head

        self.key2node = dict()

    def get(self, key: int) -> int:
        if(key not in self.key2node):
            return (-1)
        
        cur = self.key2node[key]
        self.move_front(cur)
        return cur.value

    def put(self, key: int, value: int) -> None:
        if(key not in self.key2node):
            node = Node(key, value)
            self.push_front(node)

            if(self.size > self.capacity):
                self.pop_tail()
        else:
            node = self.key2node[key]
            node.value = value
            self.move_front(node)
    
    def push_front(self, node):
        first = self.head.next

        node.next = first
        first.prev = node

        self.head.next = node
        node.prev = self.head

        self.size += 1
        self.key2node[node.key] = node
    
    def move_front(self, node):
        self.pop_node(node)
        self.push_front(node)

    def pop_node(self, node):
        prev = node.prev
        next = node.next

        prev.next = next
        next.prev = prev

        self.size -= 1
        assert node.key in self.key2node, f'key {node.key} not found!!'
        self.key2node.pop(node.key)

    def pop_tail(self):
        self.pop_node(self.tail.prev)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
