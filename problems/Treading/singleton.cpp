//
//
//#include <iostream>
//
//using namespace std;
//
//class Singleton {
//	static Singleton* instance;
//	protected:
//	Singleton() {}
//public:
//	static Singleton* getInstance()
//	{
//		if (instance == nullptr)
//			instance = new Singleton();
//		return instance;
//	}
//};
//
//Singleton* Singleton::instance;
//class D1 : public Singleton {
//	static D1* instance;
//	D1() {}
//public:
//	static D1* getInstance() {
//		if (instance == nullptr)
//			instance = new D1();
//		return instance;
//	}
//};
//D1* D1::instance;
//
//int main() {
//
//	cout << D1::getInstance << endl;
//	cout << D1::getInstance << endl;
//
//	getchar();
//
//	return 0;
//}