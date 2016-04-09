#include <iostream>
#include <string>
#include <fstream>

class StoreQuote{
public:
	std::string quote, speaker;
	std::ofstream fileOutput;

	StoreQuote();
	~StoreQuote();

	void inputQuote();
	void inputSpeaker();
	bool write();
};

StoreQuote::StoreQuote(){
	fileOutput.open("test.txt", std::ios::app);
}

StoreQuote::~StoreQuote(){
	fileOutput.close();
}

void StoreQuote::inputQuote(){
	std::getline(std::cin, quote);
}

void StoreQuote::inputSpeaker(){
	std::getline(std::cin, speaker);
}

bool StoreQuote::write(){
	if(fileOutput.is_open()){
		fileOutput << quote << "|" << speaker << "\n";
		return true;
	}
	else{
		return false;
	}
}

int main(){
	StoreQuote quote;

	std::cout << "please enter an quote:\n";
	quote.inputQuote();

	std::cout << "please enter the speaker:\n";
	quote.inputSpeaker();

	if(quote.write()){
		std::cout << "write into file successfully!\n";
	}
	else{
		std::cout << "ERROR\n";
		return 1;
	}
	return 0;
}