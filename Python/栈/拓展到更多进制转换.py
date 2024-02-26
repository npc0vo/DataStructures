'''
基于10进制转换为二进制的拓展
'''
from Stack import Stack
def baseconvert(decnumber,base):
    digits='0123456789ABCDEF'
    remStack=Stack()
    while True:
        remain=decnumber % base
        decnumber=decnumber//base
        remStack.push(remain)
        if decnumber <=0:
            break
    newString=""
    while not remStack.isEmpty():
        newString+=digits[remStack.pop()]
    return newString

print(baseconvert(25,2))
print(baseconvert(25,16))


