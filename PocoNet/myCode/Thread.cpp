/*
 * Thread.cpp
 *
 *  Created on: 9 Feb 2023
 *      Author: sanju
 */

#include "Thread.h"

using namespace std;
Thread::Thread(std::string name, std::string age)
{
	this->name = name;
	this->age = age;
}

Thread::~Thread()
{
	// TODO Auto-generated destructor stub
}

void Thread::create()
{
	Poco::Thread thread1(this->name);
	Poco::Thread thread2(this->age);
	Poco::Thread thread3("thread3");

	class runnable1: public Poco::Runnable
	{
	public:
		void run()
		{
			cout << "sanju" <<endl;
		}

	};

	class runnable2: public Poco::Runnable
	{
	public:
		void run()
		{
			cout << "vikasini" <<endl;
		}

	};

	class runnable3: public Poco::Runnable
	{
	public:
		void run()
		{
			cout << "hello" <<endl;
		}

	};

	runnable1 run1;
	runnable2 run2;
	runnable3 run3;

	thread1.start(run1);
	thread2.start(run2);
	thread3.start(run3);

	thread1.join();
	thread2.join();
	thread3.join();

//	cout << thread1.getName();

}

void Thread::getNames()
{
}
