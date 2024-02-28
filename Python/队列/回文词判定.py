from Queue2 import *
def palchecker(string):
    chardeque=Deque()
    for i in string:
        chardeque.addRear(i)
    stillEqual=True
    while stillEqual and chardeque.size()>1:
        first=chardeque.removeFront()
        last=chardeque.removeRear()
        if first != last :
            stillEqual=False
            break
    return stillEqual
print(palchecker('HUINIUH'))
print(palchecker("FUCKU"))


