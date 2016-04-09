#include <iostream>
#include <string>

class Animal{
public:
	std::string mouth;

	void eat();
	void sleep();
	void drool();

};

class Pig : public Animal{
public:
	void climb();
};

class Turtle : public Animal{
public:
	void swim();
};

void Animal::eat(){
	std::cout << "I'm eating." << std::endl;
}

void Animal::sleep(){
	std::cout << "zzz~" << std::endl;
}

void Animal::drool(){
	std::cout << "Ohh~" << std::endl;
}

void Pig::climb(){
	std::cout << "I'm climbing." << std::endl;
}

void Turtle::swim(){
	std::cout << "I'm swimming" << std::endl;
}

int main(){
	Pig pig;
	Turtle turtle;
	pig.eat();
	pig.sleep();
	pig.climb();
	turtle.swim();
	turtle.drool();

	return 0;
}