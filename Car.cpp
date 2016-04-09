#include <iostream>

#define FULL_GAS 85

class Car{
private:
	std::string color;
	std::string engine;
	unsigned int wheel;

public:
	unsigned int gas_tank;

	Car(void);

	void fillTank(int liter);
	void setColor(std::string col);
	void setWheel(unsigned int whe);
	void setEngine(std::string eng);
	int running(void);
	void warning(void);
};

Car::Car(void){
	color = "WHITE";
	engine = "V8";
	wheel = 4;
	gas_tank = FULL_GAS;
}

void Car::setColor(std::string col){
	color = col;
}

void Car::setWheel(unsigned int whe){
	wheel = whe;
}

void Car::setEngine(std::string eng){
	engine = eng;
}

int Car::running(){
	std::cout << "i'm moving\n";
	gas_tank --;
	std::cout << "you have " << 100*gas_tank/FULL_GAS << "\% gas\n";

	return gas_tank;
}

void Car::warning(){
	std::cout << "your car is running out of gas\n";
}

void Car::fillTank(int liter){
	gas_tank += liter;
}

int main(){
	char i;
	Car mycar;

	while(mycar.running()){
		if(mycar.gas_tank < 10){
			mycar.warning();
			std::cout << "Do you need to refill ur tank?(Y/N)\n";
			std::cin >> i;
			if('y' == i || 'Y' == i){
				mycar.gas_tank = FULL_GAS;
			}
		}
	}
	return 0;
}