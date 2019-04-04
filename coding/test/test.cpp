
#include <iostream>
#include <unordered_map>

using namespace std;

class abc
{
public:
	std::string str;

};
class socialM
{
public:
	static socialM getinstance()
	{
		static socialM instance;
		return instance;
	}
	int setval(abc obj)
	{
		mMap.insert({ obj.str, obj });
		return 1;
	}
private:
	unordered_map<std::string, abc>mMap;
};

int main()
{
	abc obj;
	obj.str = "10000";
	cout << socialM::getinstance().setval(obj);
	getchar();
	return 0;
}