#ifndef __NORMAL_MULTITHREAD_
#define __NORMAL_MULTITHREAD_

#include <iostream>
#include <thread>

int msum(int a,int b)
{
	int c = a + b;
	std::cout << a << "+" << b << "=" << c << std::endl;
	return c;
}

int main()
{
	std::thread t1(msum, 1, 2);
	t1.join(); // parent thread waits for child thread
	std::cout << "Main here" << std::endl;
	getchar();
	return 0;
}


#endif
