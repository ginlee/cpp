#include <iostream>
#include <string>

class BaseClass{
public:
	BaseClass();
	~BaseClass();

	void doSomething();
};

class SubClass : public BaseClass{
public:
	SubClass();
	~SubClass();
};

BaseClass::BaseClass(){
	std::cout << "I am in the Base class constructor\n";
}

BaseClass::~BaseClass(){
	std::cout << "I am in the Base class destructor\n";
}

void BaseClass::doSomething(){
	std::cout << "I am doing something\n";
}

SubClass::SubClass(){
	std::cout << "I am in the subclass constructor.\n";
}

SubClass::~SubClass(){
	std::cout << "I am in the subclass destructor.\n";
}

int main(){
	BaseClass baseclass;
	SubClass subclass;

	subclass.doSomething();
	return 0;
}