# flag=False
# i=0
# j=0
# s ="aaaaaaa"
# wordDict =["aaaa","aaa"]
# while not flag:
#     if i<=len(s)-1 and j <=len(s)-1:
#         if s[i:j+1] in wordDict:
#             i=j+1
#             j=j+1
#             continue
#     if i>len(s)-1 and j>len(s)-1:
#         flag=True
#     elif j>len(s)-1 and i <=len(s)-1:
#         break
#     j+=1
# print(flag)
flag = False
i = 0
j = 0
s = "aaaaaaa"
wordDict = ["aaaa", "aaa"]

while not flag:
    if i <= len(s) - 1 and j <= len(s) - 1:
        if s[i:j + 1] in wordDict:
            i = j + 1
            j = i
            continue
    if i > len(s) - 1 and j > len(s) - 1:
        flag = True
    elif j > len(s) - 1 and i <= len(s) - 1:
        i = j  # 修改此行，让 i 等于 j，从新的 j 开始
        j = i
    j += 1

print(flag)
