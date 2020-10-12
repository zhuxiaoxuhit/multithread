//1. 直接使用函数
void thread1_process(int code)
{
	std::cout << "code: " << code << std::endl;
}

int code  = 0; // get code from somewhere
std::thread thread1(thread1_process, code);
thread1.join(); // 等待线程结束
//tread1.detach(); // 将线程脱离thread1的管理

/**********************************************************************/
//2. 使用类成员函数
struct Task
{
 void doSomething(int task_type) {
	std::cout << "task_type: " << task_type<< std::endl; 
	// TODO
 }
};
Task task1;
std::thread thread2(&Task::doSomething, &task1, 1);
thread2.join(); // 等待线程结束
//tread2.detach(); // 将线程脱离thread2的管理

/***********************************************************************/
//3. 使用std::bind
Task task2;
std::thread thread3(std::bind(&Task::doSomething, &task2, 2));
thread3.join(); // 等待线程结束
//tread3.detach(); // 将线程脱离thread3的管理

/***********************************************************************/
//4. 使用lambda表达式
std::thread thread4([](){
	std::cout << "lambda thread called." <<std::enld; 
});
thread4.join(); // 等待线程结束
//tread4.detach(); // 将线程脱离thread4的管理
