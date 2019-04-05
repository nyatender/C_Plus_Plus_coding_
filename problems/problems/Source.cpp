

#include <iostream>

#include <vector>


using namespace std;

class Screen {
	virtual void display() = 0;
};
class LED_screen : public Screen {

};
class Keyboard {

};

class system {

};

class Admin {

};

class Customer {

};

class Printer {
	virtual void printing() = 0;
};

class ATM {

	Screen *pScreen;
	Keyboard *pkeybord;
	Printer *pPrinter;
};

auto fun1() {
	std::string str("myname");
	return str;
}
static_assert(std::is_same<decltype(fun1()), std::string>(), "");

template<typename T>
struct somecontainer {
	vector<const T*> vec;
	auto begin() const { return std::begin(vec); }
};

int main() {
	std::string ret = fun1();

	//string str = "abc";
	//int l = 6, m = 6;

	//int Snake[5] = { 14, 19, 23, 28 };

	//int **Game = new int*[l];
	//for (int i = 0; i < l; i++) 
	//	Game[i] = new int[m];
	//
	//for (int i = 0; i < l; i++) {
	//	for (int j = 0; j < m; j++) {
	//		Game[i][j] = 0;
	//		if(i < )
	//	}
	//}

	getchar();
	return 0;
}