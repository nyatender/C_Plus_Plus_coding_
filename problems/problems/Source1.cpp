//#include <iostream> 
//using namespace std;
//class Base {
//	int b;
//public:
//	void fun1() {
//		cout << " In Derive ";
//	}
//};
//class Derived : private Base { // Inherited private/protected not public 
//	void fun() {
//		cout << " In Derive ";
//	}
//};
//int main()
//{
//	Derived d1;
//	Base* b1 = (Base*)(&d1); // allowed 
//	//Base* b2 = static_cast<Base*>(&d1);
//	b1->fun1();
//	getchar();
//	return 0;
//}