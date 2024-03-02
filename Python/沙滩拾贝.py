# n, m = map(int, input().split())
# shell_love = [int(x) for x in input().split()]

# shell_love.sort(reverse=True)  # 将贝壳的喜爱度降序排序

# result = 0
# for i in range(m):
#     result &= shell_love[i]  # 计算与运算

# # print(result)
# n, m = map(int, input().split())
# shell_love = list(map(int, input().split()))

# result = 0
# for i in range(n):
#     result |= shell_love[i]

# for i in range(m - 1):
#     result |= result

def max_happiness(n, m, likes):
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] & likes[i-1])

    return dp[n][m]

# # 示例调用
# n = 5  # 贝壳数量
# m = 3  # 口袋容量
# likes = [2,10,7,3,71]  # 贝壳的喜爱度

# result = max_happiness(n, m, likes)
# print(result)
from itertools import combinations
n,m = map(int,input().split())

mylist= [int(x) for x in input().split()]
combinations_list = list(combinations(mylist, m))
for i in combinations_list:
    a=i[0]
    max=0
    for j in i:
        a&=j
    if a>max:
        max=a
print(max)







