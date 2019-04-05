/*Remove minimum number of characters so that two strings become anagram
Given two strings in lowercase, the task is to make them anagram. The only allowed operation is to remove a character from any string.
Find minimum number of characters to be deleted to make both the strings anagram?
If two strings contains same data set in any order then strings are called Anagrams.

Examples :

Input : str1 = "bcadeh" str2 = "hea"
Output: 3
We need to remove b, c and d from str1.

Input : str1 = "cddgk" str2 = "gcd"
Output: 2

Input : str1 = "bca" str2 = "acb"
Output: 0
*/

#include <iostream>

using namespace std;

int minimumNeeded(string str1, string str2)
{
	int *p1 = new int[26]{ 0 };
	int *p2 = new int[26]{ 0 };
	int count = 0;
	for (int i = 0; i < str1.size(); i++)
	{
		p1[str1[i] - 'a']++;
	}
	cout << endl;
	for (int i = 0; i < str2.size(); i++)
	{
		p2[str2[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		count += abs(p1[i] - p2[i]);
	return count;
}

int main()
{
	cout << "minimum needs to remove is " << minimumNeeded("cddgk", "cdh");

	getchar();
	return 0;
}
