from Queue2 import Queue


def hotpotatoes(queue2,num):
    queue=Queue()
    for i in queue2:
        queue.enqueue(i)
    while queue.size()>1:
        for i in range(num):
            queue.enqueue(queue.dequeue())
        queue.dequeue()    
    return queue.dequeue()

queue2=["1","2","3","4","5","6"]

print(hotpotatoes(queue2,3))
