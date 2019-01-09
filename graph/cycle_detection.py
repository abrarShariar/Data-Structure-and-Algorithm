graph = {
    'A': ['B'],
    'B': ['A', 'C'],
    'C': ['B', 'F', 'D'],
    'D': ['E','C'],
    'E': ['D'],
    'F': ['C']
};


def detect_cycle(startNode, graph, visited, parent):
    # print(len(visited), len(graph))
    if len(visited) >= len(graph):
        return False

    for n in graph[startNode]:
        if n in visited and n != parent:
            print("Detected cycle at node = ", n)
            print("Parent: ", parent)
            return True
        elif n not in visited and n != parent:
            visited.append(startNode)
            if detect_cycle(n, graph, visited, startNode):
                return True

    return False


is_cycle_present = detect_cycle('A', graph, [], '')
if is_cycle_present == False:
    print("No cycle")
