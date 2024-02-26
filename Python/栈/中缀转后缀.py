'''
从左到右扫描中缀表达式单词列表
如果单词是操作数，则直接添加到后缀表达式列表的
末尾
如果单词是左括号“(”，则压入opstack栈顶
如果单词是右括号“)”，则反复弹出opstack栈顶
操作符，加入到输出列表末尾，直到碰到左括号
如果单词是操作符
“*/+-”,则压入opstack栈顶
·但在压入之前，要比较其与栈顶操作符的优先级
如果栈顶的高于或等于它，就要反复弹出栈顶操作符
，加入到输出列表末尾
直到栈顶的操作符优先级低于它
中缀表达式单词列表扫描结束后，把
opstack栈中的所有剩余操作符依次弹出
添加到输出列表未尾
?把输出列表再用join方法合并成后缀表达
式字符串，算法结束。
'''
from Stack import Stack
def infixtopostfix(infixexpr):
    prec={}
    prec["*"]=3
    prec["/"]=3
    prec["+"]=2
    prec["-"]=2
    prec["("]=1

    opstack=Stack()
    postfixlist=[]
    tokenlist=infixexpr.split()
    for token in tokenlist:
        if token in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or token in "0123456789":
            postfixlist.append(token)
        elif token=='(':
            opstack.push(token)
        elif token==')':
            toptoken=opstack.pop()
            while toptoken !=')':
                postfixlist.append(toptoken)
                toptoken=opstack.pop()
        else:
            while (not opstack.isEmpty()) and \
                (prec[opstack.peek()]>=prec[token]):
                postfixlist.append(opstack.pop())
                opstack.push(token)
        while not opstack.isEmpty():
            postfixlist.append(opstack.pop())
        return postfixlist
        