# a=[]
# #n=rows m=cols
# n,m,M=map(int,input().split())
# for i in range(n):
#     a.append(list(map(int,input().split())))
# count=0
# def countSum(ir,ic,jr,jc):
#     sum=0
#     for row in range(ir,jr+1):
#         for col in range(ic,jc+1):
#             sum+=a[row][col]
#     return sum
# for ir in range(n):
#     for ic in range(m):
#         for jr in range(ir,n):
#             for jc in range(ic,m):
#                 if countSum(ir,ic,jr,jc) <= M:
#                     count+=1
                
# print(count)





