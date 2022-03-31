def solution(land):
    answer = 0
    
    dp = [[0] * 4 for _ in range(len(land))]
    dp[0] = land[0]
    for i in range(1, len(land)):
        for j in range(4):
            for k in range(4):
                if j == k :
                    continue
                if dp[i-1][j] + land[i][k] > dp[i][k]:
                    dp[i][k] = dp[i-1][j] + land[i][k]
    answer = max(dp[-1])
    return answer

land= [[1,2,3,5],[5,6,7,8],[4,3,2,1]]
print(solution(land))
