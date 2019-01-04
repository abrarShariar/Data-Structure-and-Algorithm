
class DisjointSet:
    def __init__(self, vertices, parent):
        self.vertices = vertices
        self.parent = parent

    def find(self, item):
        if self.parent[item] == item:
            return item
        else:
            return self.find(self.parent[item])

    def union(self, set1, set2):
        self.parent[set1] = set2

    def print_all_nodes(self):
        for v in self.vertices:
            print(self.find(v), end=" ")

        print()

def main():
    vertices = ['a', 'b', 'c', 'd', 'e', 'h', 'i']
    parent = {}

    for v in vertices:
        parent[v] = v

    ds = DisjointSet(vertices, parent)
    print("Print all vertices in genesis: ")
    # ds.print_all_nodes()

    ds.union('b', 'd')
    # ds.print_all_nodes()
    # print(ds.find('b'))
    ds.union('h', 'b')
    print(ds.find('h'))
    ds.union('i', 'h')

    print(ds.find('i'))
main()
