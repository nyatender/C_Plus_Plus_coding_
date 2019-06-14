

#include <iostream>
#include <vector>
using namespace std;

int main()
{

	int num = 0;
	cin >> num;
	vector<int>vec;
	vec.push_back(1);

	for (int i = 2; i < num; i++)
	{
		for (auto it = vec.begin(); it != vec.end(); it++)
			*it *= i;

		for (int j = 0; j < vec.size(); j++)
		{
			if (j == vec.size() - 1)
			{
				vec.push_back(0);
			}
			if (vec[j] >= 10)
			{
				vec[j + 1] = vec[j + 1] + (vec[j] / 10);
				vec[j] = vec[j] % 10;
			}
		}
	}

	//for(auto it = )

	return 0;
}