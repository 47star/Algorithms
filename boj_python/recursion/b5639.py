import sys

sys.setrecursionlimit(10**6)

preorder = []

while True:
    try:
        preorder.append(int(input()))
    except:
        break

def postorder(first, last):
    if last < first:
        return
    
    mid = last + 1

    for i in range(first + 1, last + 1):
        if preorder[first] < preorder[i]:
            mid = i
            break

    postorder(first + 1, mid - 1)
    postorder(mid, last)

    print(preorder[first])

postorder(0, len(preorder) - 1)