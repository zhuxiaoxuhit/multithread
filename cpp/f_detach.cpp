#ifndef __DETACH_
#define __DETACH_

/* join（）的作用前面已经提到，主线程等待子线程结束方可执行下一步（串行），detach（）是的子线程放飞自我，独立于主线程并发执行，主线程后续代码段无需等待。看看效果：  */

#include <iostream>
#include <thread>
#include <functional>

void hello_thread()
{
	std::cout << "Hello Thread!" << std::endl;
	std::cout << std::endl;
}

int msum(int a, int b)
{
	int c = a + b;
	std::cout << a << " + " << b << " = " << c << std::endl;
	return c;
}

int main()
{
	std::thread t1(hello_thread);
	std::thread t2(msum,2,3);
	t1.detach(); 
	t2.detach();

	std::cout << "Main here" << std::endl;

	getchar();
	return 0;
}


#endif
