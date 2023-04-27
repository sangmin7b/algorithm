class node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value
        self.is_leaf = True

def make_tree(expr):
    stack = []
    w = ""
    for c in expr:
        if c.isnumeric():
            w += c
            continue
        if w != "":
            stack.append(node(int(w)))
            w = ""
        if c == "]":
            r = stack[-1]
            l = stack[-2]
            stack.pop()
            stack.pop()
            n = node(r.value + l.value)
            n.left = l
            n.right = r
            n.is_leaf = False
            stack.append(n)
    if w != "":
        stack.append(node(int(w)))
    return stack[0]

def solve():
    expr = input()
    root = make_tree(expr)
    count = {}
    def count_weights(n, depth):
        if n.is_leaf:
            w = n.value * (2 ** depth)
            if w in count.keys() :
                count[w] = count[w] + 1
                return
            count[w] = 1
            return
        if n.left:
            count_weights(n.left, depth+1)
        if n.right:
            count_weights(n.right, depth+1)
    count_weights(root, 0)
    print(sum(count.values()) - max(count.values()))

N = int(input())
for i in range(N):
    solve()