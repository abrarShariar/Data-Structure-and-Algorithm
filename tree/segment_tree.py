# built the segment tree
import pdb
def build (node, start, end, arr, tree):
    # pdb.set_trace();
    if start == end:
        tree[node] = arr[start]
        return

    mid = int((start + end)/2)
    build((2*node + 1), start, mid, arr, tree)
    build((2*node + 2), mid + 1, end, arr, tree)
    tree[node] = tree[2*node + 1] + tree[2*node + 2]

arr = [10,5,6,1,2]
tree = [0] * ((2 * len(arr)) + 1)

build(0,0,4,arr,tree)
print(tree)
