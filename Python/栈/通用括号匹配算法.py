'''
基于简单括号匹配算法进行修改
1.碰到各种左括号依然入栈
2.碰到各种右括号需要判断栈顶的左括号是否为同一类
'''
from Stack import Stack
def padchecker(String):
    s=Stack()
    balanced=True
    index=0
    while index < len(String) and balanced:
        symbol=String[index]
        if symbol in "{([":
            s.push(symbol)
        else:
            if s.isEmpty():
                balanced=False
            else:
                top=s.pop()
                if not matches(top,symbol):
                    balanced=False
        index+=1
    if balanced and s.isEmpty():
        return True
    else:
        return False
def matches(open,close):
    opens="([{"
    closers=")]}"
    return opens.index(open)==closers.index(close)


print(padchecker("({[]})"))
print(padchecker("({{[}})"))
    

