def solution(n, arr1, arr2):
    answer = [[0] * n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            c = 2 ** (n - j - 1)
            if c - 1 < arr1[i]:
                arr1[i] -= c
                answer[i][j] = 1
            if c - 1 < arr2[i]:
                arr2[i] -= c
                answer[i][j] = 1
    
    return ["".join([" " if v == 0 else "#" for v in a]) for a in answer]