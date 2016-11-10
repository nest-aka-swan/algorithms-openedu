class Node:
    tree = None

    def __init__(self, v, left, right):
        self.v = int(v)
        self.left = int(left)
        self.right = int(right)
    
    def getLeft(self):
        if self.left is 0:
            return None
        return self.tree[self.left - 1]

    def getRight(self):
        if self.right is 0:
            return None
        return self.tree[self.right - 1]

    def height(self):
        if self.getLeft() is None and self.getRight() is None:
            return 1

        if self.getLeft() is None:
            return self.getRight().height() + 1
        if self.getRight() is None:
            return self.getLeft().height() + 1

        return max(self.getLeft().height(), self.getRight().height()) + 1

    def balance(self):
        right = self.getRight().height() if self.getRight() else 0
        left = self.getLeft().height() if self.getLeft() else 0

        return right - left

f = open('balance.in', 'r')
_, *nodes = (x.strip() for x in f.readlines())

Node.tree = [Node(*x.split()) for x in nodes]

f = open('balance.out', 'w')
for node in Node.tree:
    f.write('{}\n'.format(node.balance()))
