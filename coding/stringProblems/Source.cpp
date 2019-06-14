

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int longestPalindrom(string str, int i, int j)
{
	if (i == j)
	{
		return 1;
	}		
	else if (j < i)
		return 0;

	if (str[i] == str[j])
	{
		return 2 + longestPalindrom(str, i + 1, j - 1);
	}
	else
	{
		return max(longestPalindrom(str, i, j - 1), longestPalindrom(str, i+1, j));
	}
	
}

void longParindrom(std::string str)
{
	int low = 0;
	int high = str.size()-1;
	int count = 0;
/*	for (int i = 0; i < str.size(); i++)
	{
		if*/ 
	while(low < high)
	{
		if (str[low] == str[high])
		{
			count++;
			low++;
			high--;
		}
		else
		{
			low++;
		}
	}

}

void allPalimdromicSequence(std::string str)
{
	int low  = 0;
	int high = 0;
	int n = str.length();
	vector<string>mMap;
	mMap.push_back({ str.substr(0, 1) });
	for (int i = 1; i < n; i++)
	{
		low  = i-1;
		high = i;
		mMap.push_back({str.substr(i, 1) });
		while (low >= 0 && high < n && str[low] == str[high])
		{
			mMap.push_back(str.substr(low, high-low + 1));
			low--;
			high++;
		}
		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < n && str[low] == str[high])
		{
			mMap.push_back({ str.substr(low, high-low + 1) });
			low--;
			high++;
		}
	}
	for (auto it = mMap.begin(); it != mMap.end(); it++)
		cout << (*it).c_str() << " ";
}

void palindrom(string str)
{
	vector<string>vec;
	for (int p = 0; p < str.length(); p = p+.5)
	{
		int pR = p - (int)p;
		while ((p + pR) > 0 && (p - pR) < str.length() && str[p + pR] == str[p - pR])
		{
			vec.push_back(str.substr((p + pR), p - pR));
		}
	}
}

int imain()
{
	allPalimdromicSequence("hellolle");


	getchar();
	return 0;
}