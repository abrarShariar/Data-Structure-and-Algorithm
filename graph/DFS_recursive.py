class node:
    def __init__(self, value):
        self.value = value
        self.visited = False
        self.neighbours = []


def DFS(s):
    print(s.value)
    s.visited = True
    for x in s.neighbours:
        if x.visited == False:
            DFS(x)
    return

n1, n2, n3, n4, n5 = [node(1), node(2), node(3), node(4), node(5)]
n1.neighbours = [n2, n3]
n2.neighbours = [n1, n4, n5]
n3.neighbours = [n1]
n4.neighbours = [n2]
n5.neighbours = [n2]

DFS(n1)
