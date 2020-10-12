#ifndef __D_INCLASS_
#define __D_INCLASS_

#include <iostream>
#include <thread>
#include <functional>

class HelloWorld
{
	public:
		void hello(int year)
		{
			std::cout << "I am " << year << " years old" << std::endl;
		}
};

int main(int argc,char* argv[])
{
	HelloWorld obj;
	std::thread thrd(std::bind(&HelloWorld::hello,&obj,26));  //std::band - 参数绑定
	thrd.join();

	getchar();
	return 0;
}


#endif
