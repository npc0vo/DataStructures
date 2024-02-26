'''
一个具体的实例配置如下：
一个实验室，在任意的一个小时内，大约有1日名
学生在场，
这一小时中，每人会发起2次左右的打印，每次1
≈20页
打印机的性能是：
以草稿模式打印的话，每分钟10页，
以正常模式打印的话，打印质量好，但速度下降
为每分钟5页。
'''
'''
打印任务问题：模拟流程
创建打印队列对象
。时间按照秒的单位流逝
按照概率生成打印作业，加入打印队列
如果打印机空闲，且队列不空，则取出队首作业
打印，记录此作业等待时间
如果打印机忙，则按照打印速度进行1秒打印
如果当前作业打印完成，则打印机进入空闲
时间用尽，开始统计平均等待时间
'''
class Printer:
    def __init__(self,ppm):
        self.pagerate=ppm
        self.currentTask=None
        self.timeRemaining=0
    def tick(self):
        if self.currentTask!=None:
            self.timeRemaining=self.timeRemaining-1
            if self.timeRemaining<=0:
                self.currentTask=None
    def busy(self):
        if self.currentTask!=None:
            return True
        else:
            return False
    def startNext(self,newtask):
        self.currentTask=newtask
        self.timeRemaining=newtask.getPages()\
        *60/self.pagerate


        