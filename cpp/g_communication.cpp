#ifndef __COMMUNICATION_
#define __COMMUNICATION_

#include <iostream>
#include <thread>
#include <mutex>


/*  线程间数据共享，当多个线程同时操作同一个数据时，需要加入线程锁，保证同时操作一个数据的安全性  */

std::mutex mt;
int data = 1;

void addmethod(int a)
{
	mt.lock();
	data += a;
	std::cout << "add data=" << data << std::endl;
	mt.unlock();
}

void multimethod(int a)
{
	mt.lock();
	data *= a;
	std::cout << "multipy add=" << data << std::endl;
	mt.unlock();
}

int main()
{
	std::thread t1(addmethod,2);
	std::thread t2(multimethod,10);

	t1.detach();
	t2.detach();

	getchar();
	return 0;
}


#endif

