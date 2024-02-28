s=str(input())
t=str(input())
maxlen=max(len(s),len(t))
res=""
s=s.zfill(maxlen)
t=t.zfill(maxlen)
canary=0
for i in range(maxlen-1,-1,-1):
    sum=ord(s[i])-ord('0')+ord(t[i])-ord('0') + canary
    if sum <10:
        res+=str(sum)
        canary=0
    else:
        canary=1
        res+=str(sum-10)
if canary:
    res+='1'
print(res[::-1])


            