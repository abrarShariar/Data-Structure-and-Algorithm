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


totalNodes = 5
nodeList = [node(i) for i in range(totalNodes+1)]
nodeList[1].neighbours = [nodeList[2], nodeList[3]]
nodeList[2].neighbours = [nodeList[1], nodeList[4], nodeList[5]]
nodeList[3].neighbours = [nodeList[1]]
nodeList[4].neighbours = [nodeList[2]]
nodeList[5].neighbours = [nodeList[2]]

DFS(nodeList[1])
