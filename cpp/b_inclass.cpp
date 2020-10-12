#ifndef __MULTITHREAD_IN_CLASS_
#define __MULTITHREAD_IN_CLASS_

#include <iostream>
#include <thread>

class HelloThread
{
	public:
		static void hellothread()
		{
			std::cout << "Hello world, I\"m a thread!" << std::endl;
		}

		static void start()
		{
			std::thread thrd(HelloThread::hellothread);
			thrd.join();
		}
};

int main()
{
	HelloThread::start();
	getchar();
	return 0;
}

#endif
