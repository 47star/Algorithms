def solution(s):
    a = ""
    i = 0
    l = len(s)
    m = {
        "zero": "0",
        "one": "1",
        "two": "2",
        "three": "3",
        "four": "4",
        "five": "5",
        "six": "6",
        "seven": "7",
        "eight": "8",
        "nine": "9",
    }
    
    while i < l:
        if 47 < ord(s[i]) < 58:
            a += s[i]
            i += 1
            continue
        
        for j in range(3, 6):
            v = s[i:i + j]
            if v in m:
                a += m[v]
                i += j
                break
    
    return int(a)