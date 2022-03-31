import itertools

def solution(numbers):
    max_num = 10 ** len(numbers)
    l = [True] * max_num
    per = []
    prime = {}
    num = []
    cnt = 0
    
    numbers = list(numbers)
    
    for i in range(2, int((max_num ** 0.5)) + 2):
        for j in range(i * i, max_num, i):
            l[j] = False
            
    for i in range(2, max_num):
        if l[i]:
            prime[str(i)] = True
    
    for i in range(1, len(numbers) + 1):
        tmp = itertools.permutations(numbers, i)
        per.append(list(tmp))
        
    for i in range(len(per)):
        for j in range(len(per[i])):
            num.append(''.join(per[i][j]))
            
    num = set(num)
    for i in num:
        if i in prime.keys():
            cnt += 1
                
    return cnt
        
numbers = "17"
print(solution(numbers))
