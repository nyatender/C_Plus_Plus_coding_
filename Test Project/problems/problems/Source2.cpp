
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;


void printFrequencies(const string str) {

	unordered_multimap<string, int> WordF;
	unordered_multiset<int> WordS;
	std::stringstream strS(str);
	string s;
	int count = 0;
	while (strS >> s)
		WordF.insert(make_pair(s, count++));

	cout << WordF.bucket_size(7) << endl;

	for (auto it = WordF.begin(); it != WordF.end(); it++) {		
		cout << it->first << " " << it->second << endl;
	}
}

class abc {
private:
	int a;
public:
	abc() {
		cout << " default contr " << endl;
	}
	abc(abc *obj) {
		cout << " using poinnter " << endl;
	}
	abc(abc& obj) {
		cout << " using reference " << endl;
	}
};

void fun1(abc *p1) {
	cout << " In fun1() " << endl;
}
void fun2(abc p2) {
	cout << " In fun2 " << endl;
}

abc* fun3() {
	return new abc();
}
abc fun() {
	abc obj;
	return obj;
}

void ZAlgo(string text, string pattern) {
	string res = pattern + "$" + text;
	int len = res.length();
	int *ZArr = new int[len];

	int left = 0, right = 0;

	for (int i = 1;i < len;i++) {
		if (right < i) {
			left = right = i;
			while (right < len && ZArr[right] == ZArr[right - left])
				right++;
			ZArr[i] = ZArr[right - left];
			right--;
		}
		else {
			int k = i - left;
			if (ZArr[k] < right - i + 1)
				ZArr[i] = ZArr[k];
			else {
				left = i;
				while (right < len && ZArr[right] == ZArr[right - left])
					right++;
				ZArr[i] = ZArr[right - left];
				right--;
			}
		}
	}

}

template<class T, class U=int>
class A {
public:
	T x;
	U y;
};

int* calculateZArr(string str, string pattr) {

	string mStr = pattr + "$" + str;
	int n = mStr.length();
	int *Z = new int[n];

	int l = 0;
	int r = 0;

	for (int i = 1; i < n; i++) {
		if (r < i) {
			l = r = i;
			while (r < n && str[l] == str[r - l]) 
				r++;
			Z[i] = r - l;
			r--;
		}
		else {
			int k = i - l;
			if (Z[k] < r - i + 1)
				Z[i] = Z[k];
			else {
				l = i;
				while (r < n && str[l] == str[r - l])
					r++;
				Z[i] = r - l;
				r--;
			}
		}
	}	

	return Z;
}

int patterMatching(string str, string pattr) {

	int len = str.length() + pattr.length();
	
	int * Z = calculateZArr(str, pattr);

	return 0;
}

int main()
{
	string pattern = "abc";
	string text = "sdfabcsdfabc";
	ZAlgo(text, pattern);
	/*abc obj1(new abc());
	fun1(&obj1);
	fun2(obj1);*/
	abc* b = fun3();
	fun();



	/*string str = "geeks for geeks geeks quiz "
				 "practice qa for";
	printFrequencies(str);*/
	getchar();
	return 0;
}