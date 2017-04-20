#coding=utf-8
import threading
import time


# 为线程定义一个函数
def print_time(threadName, delay):
    count = 0
    while count < 5:
        time.sleep(delay)
        count += 1
        print(threadName, time.ctime(time.time()))


# 创建两个线程
threads=[]
try:
    t1=threading.Thread(target=print_time,args=("Thread-1", 2))
    threads.append(t1)
    t2=threading.Thread(target=print_time,args=("Thread-2", 4))
    threads.append(t2)
except:
    print("Error: unable to start thread")

if __name__ == '__main__':
    for t in threads:
#        t.setDaemon(True)
        t.start()

#if __name__ == '__main__':
#    print_time("Thread-2", 4)

s1="all over is " + time.ctime()
print(s1)
