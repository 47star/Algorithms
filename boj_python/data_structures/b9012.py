for _ in range(int(input())):
    chars = list(str(input()))
    stack = []

    no = False
    
    for char in chars:
        if char == "(":
            stack.append("(")
        elif len(stack) == 0:
            no = True
            break
        else:
            stack.pop()
    
    if len(stack) != 0:
        no = True
    
    if no == False:
        print("YES")
    else:
        print("NO")