def solution(id_list, report, k):
    answer = {}
    reported = {}
    for id in id_list:
        answer[id] = 0;
        reported[id] = [];
    
    for r in report:
        a, b = r.split(" ")
        if not(a in reported[b]):
            reported[b].append(a)
    
    for id in id_list:
        if k - 1 < len(reported[id]):
            for p in reported[id]:
                answer[p] += 1;
    
    return [answer[id] for id in id_list]