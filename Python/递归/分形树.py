import turtle
t=turtle.Turtle()
#开始作图
'''螺旋线'''
def drawSpiral(t,lineLen):
    if lineLen >0:
        t.forward(lineLen)
        t.right(90)
        drawSpiral(t,lineLen-1)
'''分形树'''
def tree(branch_len):
    if branch_len <5:
        return
    else:
        t.forward(branch_len)
        t.right(20)
        tree(branch_len-15)
        t.left(40)
        tree(branch_len-15)
        t.right(20)
        t.backward(branch_len)
t.left(90)
t.penup()
t.backward(100)
t.pendown()
t.pencolor('green')
t.pensize(2)
tree(75)
t.hideturtle




turtle.done()
