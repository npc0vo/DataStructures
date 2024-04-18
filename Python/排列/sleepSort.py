import _thread
from time import sleep

items = [6, 3, 4, 1, 3, 7]

def sleep_sort(i):
    sleep(i)
    print(i)

# 启动线程
threads = [_thread.start_new_thread(sleep_sort, (i,)) for i in items]

# 等待一段时间确保所有子线程有足够时间执行
sleep(max(items) + 1)

# 注意：在实际应用中，最好使用 threading 模块而不是 _thread


