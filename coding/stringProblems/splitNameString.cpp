

#include <iostream>
#include <vector>

using namespace std;

void foo(int& arg)
{
	cout << arg;
}

template<class T>
T&& forward(typename remove_reference<T>::type& arg)
{
	return static_cast<T&&>(arg);
}

template<typename T>
void relay(T&& arg)
{
	foo(std::forward<T>(arg));
}

void print(int arg)
{
	cout << arg << endl;
}

template<typename T, typename... types>
void print(const T &first, const types... args)
{
	cout << first << endl;
	print(args...);
}

int main()
{
	print(4);
	int i = 9;
	relay(i);
	relay(10);

	getchar();
	return 0;
}