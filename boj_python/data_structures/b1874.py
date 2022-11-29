import sys

stack = []
actions = []
n = int(input())
last = 0

for _ in range(n):
    m = int(input())

    if len(stack) != 0 and stack[-1] == m:
        stack.pop()
        actions.append("-")
        continue

    if last < m + 1:
        while last < m:
            last = last + 1
            stack.append(last)
            actions.append("+")
            if stack[-1] == m:
                stack.pop()
                actions.append("-")
        continue
    
    print("NO")
    sys.exit(0)

print("\n".join(actions))