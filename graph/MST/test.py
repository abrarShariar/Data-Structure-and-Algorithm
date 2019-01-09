
nodes = {
    0: [1, 7],
    1: [0, 7, 2],
    2: [1, 8, 5, 3],
    3: [2, 5, 4],
    4: [3, 5],
    5: [2, 3, 4, 6],
    6: [7, 8, 5],
    7: [0, 1, 8, 6],
    8: [2, 7, 6]
};

# print(len(nodes))

# DFS
def DFS(startNode, graph, visited):
    if len(visited) > len(nodes):
        return
    visited[startNode] = True
    print(startNode)
    for n in nodes[startNode]:
        if visited[n] == False:
            DFS(n, graph, visited)







DFS(0, nodes, [False for i in range(len(nodes))])
