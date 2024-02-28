def toStr(num,base):
    convertString="0123456789abcdef"
    if num < base:
        return convertString[num]
    else:
        return toStr(num//base,base)+convertString[num%base]
print(toStr(999,2))