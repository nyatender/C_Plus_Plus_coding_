

#include <iostream>
#include <vector>

using namespace std;

void SplitStr(std::string str)
{
	if (str.empty())
		return;

	int i = 0;
	vector<int>pos;
	while (++i < str.size())
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			pos.push_back(i);
	}
	pos.push_back(i);
	i = 0;
	for (auto a = pos.begin(); a != pos.end(); a++)
	{
		cout << str.substr(i, (*a - i)).c_str() << " ";
		i = *a;
	}
}

int main()
{

	//split the world in a meaningful name 
	string name = "YatenderSinghNegi";
	SplitStr(name);

	getchar();
	return 0;
}