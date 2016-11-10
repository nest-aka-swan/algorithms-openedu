class Node:
    def __init__(self, parent, value):
        self.key = value
        self.left = None
        self.right = None
        self.parent = parent

    def insert(self, value):
        if value < self.key:
            if self.left is None:
                self.left = Node(self, value)
                return self.left
            else:
                return self.left.insert(value)
        else:
            if self.right is None:
                self.right = Node(self, value)   
                return self.right
            else:
                return self.right.insert(value)

    def find(self, value):
        if value == self.key:
            return self
        elif value < self.key:
            if self.left is None:
                return None
            else:
                return self.left.find(value)
        else:
            if self.right is None:
                return None
            else:
                return self.right.find(value)
    
    def next(self):
        if self.right is not None:
            return self.right.minimum()
        current = self
        while current.parent is not None and current.parent.right is current:
            current = current.parent
        return current.parent

    def prev(self):
        if self.left is not None:
            return self.left.maximum()
        current = self
        while current.parent is not None and current.parent.left is current:
            current = current.parent
        return current.parent

    def delete(self):
        if self.left is None or self.right is None:
            if self is self.parent.left:
                self.parent.left = self.left or self.right
                if self.parent.left is not None:
                    self.parent.left.parent = self.parent
            else:
                self.parent.right = self.left or self.right
                if self.parent.right is not None:
                    self.parent.right.parent = self.parent 
            current = self.parent
            while current.key is not None:
                current = current.parent
            return self
        else:
            s = self.next()
            self.key, s.key = s.key, self.key
            return s.delete()

    def minimum(self):
        current = self
        while current.left is not None:
            current = current.left
        return current

    def maximum(self):
        current = self
        while current.right is not None:
            current = current.right
        return current

class BST:
    def __init__(self):
        self.root = None
        self.psroot = Node(None, None)

    def reroot(self):
        self.root = self.psroot.left

    def insert(self, value):
        if self.root is None:
            self.psroot.left = Node(self.psroot, value)
            self.reroot()
            return self.root
        else:
            return self.root.insert(value)

    def exists(self, value):
        if self.root is None:
            return None
        else:
            return self.root.find(value)

    def next(self, value):
        node = self.exists(value)
        if node:
            return node.next().key
        else:
            nxt = self.insert(value).next().key
            self.delete(value)
            return nxt
    
    def prev(self, value):
        node = self.exists(value)
        if node:
            return node.prev().key
        else:
            prv = self.insert(value).prev().key
            self.delete(value)
            return prv

    def delete(self, value):
        node = self.exists(value)
        deleted = self.root.delete()
        self.reroot()
        return deleted

tree = BST()

fin = open('bstsimple.in', 'r')
fout = open('bstsimple.out', 'w')
for line in fin.readlines():
    cmd, val = line.split()
    val = int(val)
    
    if cmd == 'insert':
        tree.insert(val)
        continue
    elif cmd == 'exists':
        node = tree.exists(val)
        fout.write('true\n') if node else fout.write('false\n')
        continue
    elif cmd == 'next':
        nxt = tree.next(val)
        fout.write(str(nxt).lower()+'\n')
        continue
    elif cmd == 'prev':
        prv = tree.prev(val)
        fout.write(str(prv).lower()+'\n')
        continue
    elif cmd == 'delete':
        tree.delete(val)
        continue
