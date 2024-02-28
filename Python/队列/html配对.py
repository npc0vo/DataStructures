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


def HTMLMatch(s) -> bool:
    def isOpenTag(tag):
        return tag[1]!="/"
    def matches(open,close):
        return open==close.replace("/","")
    def getTag(s,i):
        t=""
        while s[i]!=">":
            t+=s[i]
            i+=1
        t+=">"
        return t,i  #t是起始位置  i是结束位置
    st=Stack()
    balanced=True
    index=0
    while index < len(s) and balanced:
        symbol = s[index]
        if symbol == "<":
            tag,index=getTag(s,index)
        if isOpenTag(tag):
            st.push(tag)
        else:
            if st.isEmpty():
                balanced=False
            else:
                top=st.pop()
                if not matches(top,tag):
                    balanced=False
        #忽略所有非标记内容
        while index < len(s) and s[index]!="<":
            index+=1
    if balanced and st.isEmpty():
        return True
    else:
        return False
print(HTMLMatch("<HELLO></HELLO>"))
