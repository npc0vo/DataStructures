def seSearch(list,item):
    pos=0
    found=False
    flag=0
    stop=False

    while pos <= len(list)-1 and not stop:
        if list[pos]==item:
            found=True
            flag=pos
        else:
            if list[pos]>item:
                stop=True
        pos+=1

    return found,flag


testList=[3,4,6,10,12,33,45]
found,flag=seSearch(testList,10)
print(f"{found}+{flag}")
