from Stack import Stack

def divideBy2(decNumber):
    remStack=Stack()
    while True:
        remain = decNumber % 2
        decNumber = decNumber //2
        remStack.push(remain)
        if decNumber <=0:
            break
    binString=""
    while not remStack.isEmpty():
        binString+=str(remStack.pop())
    return binString

print(divideBy2(42))

