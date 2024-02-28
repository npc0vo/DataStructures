
'''
初始化两个栈：运算符栈s1和储存中间结果的栈s2；
从左至右扫描中缀表达式；
遇到操作数时，将其压s2；
遇到运算符时，比较其与s1栈顶运算符的优先级：
如果s1为空，或栈顶运算符为左括号“(”，则直接将此运算符入栈；
否则，若优先级比栈顶运算符的高，也将运算符压入s1（注意转换为前缀表达式时是优先级较高或相同，而这里则不包括相同的情况）；
否则，将s1栈顶的运算符弹出并压入到s2中，再次转到(4-1)与s1中新的栈顶运算符相比较；
遇到括号时：
如果是左括号“(”，则直接压入s1；
如果是右括号“)”，则依次弹出s1栈顶的运算符，并压入s2，直到遇到左括号为止，此时将这一对括号丢弃；
重复步骤2至5，直到表达式的最右边；
将s1中剩余的运算符依次弹出并压入s2；
依次弹出s2中的元素并输出，结果的逆序即为中缀表达式对应的后缀表达式（转换为前缀表达式时不用逆序）
'''
class Stack(object):   #定义栈 属性
    """栈"""
    def __init__(self):
         self.items = []

    def isEmpty(self):
        """判断是否为空"""
        return self.items == []

    def push(self, item):
        """加入元素"""
        self.items.append(item)

    def pop(self):
        """弹出元素"""
        return self.items.pop()

    def peek(self):
        """返回栈顶元素"""
        return self.items[len(self.items)-1]

    def size(self):
        """返回栈的大小"""
        return len(self.items)

def infixToPostfix(infixexpr):
    '''
    记录操作符优先级
    '''
    prec={}
    prec["*"]=3
    prec["/"]=3
    prec["+"]=2
    prec["-"]=2
    prec["("]=1
    
    opStack=Stack()
    postfixList=[] #后缀表达式列表
    tokenList=list(infixexpr)
    # print(tokenList)


    for token in tokenList:
        if token in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or token in "0123456789":
            postfixList.append(token)
        elif token == '(':
            opStack.push(token)
        elif token == ")":
            toptoken=opStack.pop()
            while toptoken != '(':
                postfixList.append(toptoken)
                toptoken=opStack.pop()
        else:
            while (not opStack.isEmpty()) and \
            (prec[opStack.peek()]>=prec[token]):
                postfixList.append(opStack.pop())
            opStack.push(token)
    while not opStack.isEmpty():
        postfixList.append(opStack.pop())
    print("".join(postfixList))
    return "".join(postfixList)
def postfixEval(postfixExpr):
    operandStack=Stack()
    tokenList=list(postfixExpr)
    
    for token in tokenList:
        if token in "0123456789":
            operandStack.push(int(token))
        else:
            operand2=operandStack.pop()
            operand1=operandStack.pop()
            result=doMath(token,operand1,operand2)
            operandStack.push(result)
    return operandStack.pop()
def doMath(token,operand1,operand2):
    if token == "*":
        return operand1*operand2
    elif token == "/":
        return operand1/operand2
    elif token == "+":
        return operand2+operand1
    elif token == "-":
        return operand1+operand2
    else:
        return False

print(infixToPostfix("1*2+3*4"))
print(postfixEval(infixToPostfix("1*2+3*4")))

                