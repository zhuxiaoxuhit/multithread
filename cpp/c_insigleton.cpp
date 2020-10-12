#ifndef __MULTITHREAD_IN_SINGLETON_
#define __MULTITHREAD_IN_SINGLETON_

#include <iostream>
#include <thread>
#include <functional>

class HelloWorld
{
	public:
		void hello()
		{
			std::cout << "Hello world, I \"m a thread!" << std::endl;
		}
		static void start()
		{
			std::thread thrd(std::bind(&HelloWorld::hello,&HelloWorld::getInstace()));  //参数绑定
			thrd.join();
		}
		static HelloWorld& getInstace()
		{
			if (!instance)
			{
				instance = new HelloWorld;
			}
			return *instance;
		}

	private:
		HelloWorld() {}
		static HelloWorld* instance;
};

HelloWorld* HelloWorld::instance = 0;

int main(int argc, char* argv[])
{
	HelloWorld::start();
	getchar();
	return 0;
}

#endif
