

#include <iostream> 
#include <vector>
#include <list>

using namespace std;

class MyString {

	char* p;

public:
	MyString() {
		cout << " Constructor" << endl;
	}

	MyString(char* ptr) {
		int len = strlen(ptr);
		p = new char[len+1];
	}

	~MyString() {
		if(p != NULL)
			delete[] p;
	}

	MyString(const MyString & obj) {
		int n = strlen(obj.p);
		p = new char[n+1];
		for (int i = 0; i < n; i++) {
			p[i] = obj.p[i];
		}
		p[n - 1] = '\0';
	}

	MyString operator=(const MyString& obj) {
		if (this != &obj) {
			delete[] p;
			int n = strlen(obj.p);
			p = new char[n + 1];
			for (int i = 0; i < n; i++) {
				p[i] = obj.p[i];
			}
			p[n - 1] = '\0';
		}
		return *this;
	}

	void* operator new(size_t size) {
		void *p = malloc(size);
		return p;
	}

	void operator delete(void* p) {
		free(p);
		p = NULL;
	}

};

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void toSegregateNum(int arr[], int n) {

	int i = 0, j = 1, k = n - 1;

	if (n == 1)
		return;

	while (j < k && i < k) {

		while (i < n - 1 && arr[i] == 0)
			i++;

		while (j < n - 1 && arr[j] == 1)
			j++;

		swap(&arr[i], &arr[j]);

		while (k > j && arr[k] == 2)
			k--;

		swap(&arr[j], &arr[k]);
	}
}

int min(int a, int b) {
	return (a > b ? a : b);
}


void buildSegmentTree(int seg[], int arr[], int pos, int low, int high) {

	if (low == high) {
		seg[pos] = arr[low];
		return;
	}
	int mid = (low + high) / 2;
	buildSegmentTree(seg, arr, 2*pos+1, low, mid);
	buildSegmentTree(seg, arr, 2*pos+2, mid+1, high);

	seg[pos] = min(seg[2 * pos + 1], seg[2 * pos + 2]);
}

int searchQuery(int seg[], int pos, int low, int high, int qlow, int qhigh) {

	if (qlow < low && qhigh > high)
		return seg[pos];
	if (qhigh < low || qlow > high)
		return INT_MAX;

	int mid = (low + high) / 2;

	int left = searchQuery(seg, 2 * pos + 1, low, mid, qlow, qhigh);
	int right = searchQuery(seg, 2 * pos + 2, mid+1, high, qlow, qhigh);

	return (left < right ? left : right);
}

void segmentTree(int arr[], int n) {

	int len = 2 * n - 1;
	int *Segment = new int[len];
	buildSegmentTree(Segment, arr, 0, 0, len-1);

}

void palindromeSubSequence(string str, int i, int j) {

	if (i == j) {
		cout << str[i] << endl;
		return;
	}

	if (str.length() == 2 && str[0] == str[1]) {
		cout << str.c_str();
		return;
	}

	if (str[i] == str[j]) {
		palindromeSubSequence(str, i + 1, j - 1);
	}

	return (palindromeSubSequence(str, i, j - 1), palindromeSubSequence(str, i+1, j));

}

int max(int a, int b) {

	return (a > b ? a : b);
}

int longestPalindromicSub(string str, int i, int j) {

	if (i > j)
		return 0;

	if ( i == j)
		return 1;

	if (str[i] == str[j]) {
		return (1 + longestPalindromicSub(str, i + 1, j - 1));
	}

	return max(longestPalindromicSub(str, i, j - 1), longestPalindromicSub(str, i + 1, j));
}

void printVector(list<string>vec) {

	for (auto it = vec.begin(); it != vec.end(); it++)
		cout << (*it).c_str() << " ";

}

bool possiblePartition(string str, int i, int j, list<string>vec) {

	if (i == j) {
		vec.push_back(str.substr(i, j));
		return true;
	}

	if (str.length() == 2 && str[i] == str[j]) {
		vec.push_back(str.substr(i, j));
		return true;
	}

	if (possiblePartition(str, i + 1, j - 1, vec) && str[i] == str[j]) {
		vec.push_back(str.substr(i, j));
		return true;
	}
	else {
		vec.push_back(str.substr(i, 1));
		vec.push_back(str.substr(j, 1));
		return possiblePartition(str, i + 1, j, vec) || possiblePartition(str, i, j - 1, vec);		
	}
}


bool isPalindrpm(string str) {
	return true;
}

void allPalindromic(vector<vector<string>>&vec, vector<string>sVec, string& s, int index) {
	string str;
	for (int i = index; i < s.length(); i++) {
		str = str + s[i];
		if (isPalindrpm(str)) {
			sVec.push_back(str);
			if (i + 1 < s.length())
				allPalindromic(vec, sVec, s, i + 1);
			else
				vec.push_back(sVec);
		}
	}
}

int ToAddForPalindromic(string str) {

	if (str.length() == 1 || (str.length() == 2 && str[0] == str[1]))
		return 0;

	if (longestPalindromicSub(str, 0, str.length() - 1))
		return 1;

	return str.length() - 1;
}

vector<string> palindromicSub(string str) {

	vector<string> v;
	int len = str.length();

	for (float radius = 0; radius < len; radius++) {

		float pRadius = radius - (int)radius;

		while ((radius + pRadius < len) &&
				(radius - pRadius) >= 0 &&
				str[(int)(radius - pRadius)] == str[(int)(radius + pRadius)]) {

			int start = (int)(radius - pRadius);
			int end = (int)(radius + pRadius);
			v.push_back(str.substr(start, end));

			pRadius++;
		}
	}

	return v;
}

void possiblePartitionUtil(string str, int i, int j) {

	for (int i = 0; i < str.length(); i++) {
		list<string>vec;
		possiblePartition(str, 0, i, vec);
		possiblePartition(str, i, j, vec);
		printVector(vec);
	}
}

bool palindromicPair(string str[]) {


	return true;
}

int main() {

	string list[] = { "geekf", "geeks", "or", "keeg", "abc", "bc" };

	palindromicPair(list);

	string str = "nitin";

	possiblePartitionUtil(str, 0, str.length() - 1);	


	int i1 = int(0.5);

	int i = 10;
	int j = move(i);

	cout << i << j;

	int arr[] = { 2,2,0,1,0,2,2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	toSegregateNum(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	getchar();

	/*MyString *obj = new MyString();
	delete obj;

	vector<vector<int>>vec;
	for (int i = 0; i < 100; i++) {
		vector<int> v;
		v.push_back(i);
		vec.push_back(v);
	}
	for (auto i = vec.begin(); i != vec.end(); i++) {
		for (auto j = (*i).begin(); j != (*i).end(); j++)
			cout << *j << endl;
	}

	string str = "abc";
	cout << str.data() << endl;	
	str += "cdf";
	cout << str.data() << endl;
*/
	return 0;
}

