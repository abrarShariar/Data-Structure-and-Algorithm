class Node:
    def __init__(self, value):
        self.value = value
        self.visited = False
        self.neighbours = []


class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, element):
        self.queue.append(element)

    def dequeue(self):
        if len(self.queue) > 0:
            return self.queue.pop(0)
        else:
            raise ValueError('Queue is empty')

    def isEmpty(self):
        if len(self.queue) > 0:
            return False
        else:
            return True


def BFS(s):
    queue = Queue()
    s.visited = True
    queue.enqueue(s)

    while queue.isEmpty() == False:
        v = queue.dequeue()
        print(v.value)
        for x in v.neighbours:
            if x.visited == False:
                x.visited = True
                queue.enqueue(x)

totalNodes = 7
nodeList = [Node(i) for i in range(totalNodes+1)]

nodeList[0].neighbours = [nodeList[1], nodeList[2], nodeList[3]]
nodeList[1].neighbours = [nodeList[4], nodeList[5]]
nodeList[2].neighbours = [nodeList[6], nodeList[7]]
nodeList[3].neighbours = [nodeList[7]]
nodeList[4].neighbours = [nodeList[1]]
nodeList[5].neighbours = [nodeList[1]]
nodeList[6].neighbours = [nodeList[2]]
nodeList[7].neighbours = [nodeList[3]]

BFS(nodeList[0])
