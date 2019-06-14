//
//
//#include<iostream>
//#include <vector>
//#include <thread>
//#include <map>
////#include <string>
//
//using namespace std;
//
//void ConstructTree(int arr[], int SegmentArr[], int low, int high, int pos) {
//
//	if (low == high) {
//		SegmentArr[pos] = arr[low];
//		return;
//	}
//	int mid = (low + high) / 2;
//	ConstructTree(arr, SegmentArr, low, mid, 2*pos+1);
//	ConstructTree(arr, SegmentArr, mid + 1, high, 2*pos+2);
//
//	//SegmentArr[pos] = min(SegmentArr[2 * pos + 1], SegmentArr[2 * pos + 2]);
//
//}
//
//bool isValid_Num(char* p) {
//	int num = -1;
//	while (*p != '\0') {
//		num = *p - '0';
//		if (!(num >= 0 && num <= 9))
//			return false;
//		p++;
//	}
//	return true;
//}
//
//bool isValid_ip(char* p) {
//	if (p == NULL || strlen(p) > 15)
//		return 0;
//	char* buffer;
//	char *str = strtok_s(p, ".", &buffer);
//	int dots = 0;
//	int num = -1;
//
//	while (str != nullptr) {
//		isValid_Num(str);
//
//		num = atoi(str);
//		if (num > 0 && num <= 255) {
//			str = strtok_s(NULL, ".", &buffer);
//			if(str != NULL)
//				dots++;
//		}
//		else
//			return false;
//	}
//	if (dots != 3)
//		return false;
//	
//	return true;
//}
//
//void pritAllOnesUtils(string str, int k) {
//	int len = str.length();
//	if (k == len) {
//		cout << str.c_str() << endl;
//		return;
//	}
//	if (str[len - 1] == '0') {
//		pritAllOnesUtils(str + "1", k);
//		pritAllOnesUtils(str + "0", k);
//	}
//	else
//		pritAllOnesUtils(str + "0", k);
//}
//
//void pritAllOnes(int k) {
//	pritAllOnesUtils("1", k);
//	pritAllOnesUtils("0", k);
//}
//#define MAX_SIZE 100
//void printAllValidParenthesUtils(int pos, int len, int close, int open) {
//	static char arr[MAX_SIZE];
//	if (close == len)
//	{
//		cout << arr << endl;
//		return;
//	}
//	if (close < open) {
//		arr[pos] = '}';
//		printAllValidParenthesUtils(pos+1, len, close + 1, open);
//	}
//	if (open < len) {
//		arr[pos] = '{';
//		printAllValidParenthesUtils(pos+1, len, close, open + 1);
//	}
//}
//
//void printAllValidParenthes(int k) {
//	printAllValidParenthesUtils(0, k, 0, 0);
//}
//
//class ABC
//{
//	int *ptr;
//	int len;
//	//ostream& ob;
//public:
//
//	virtual ~ABC()=0 {
//		cout << " ABC Destructor " << endl;
//	}
//	ABC(int i) {
//		len = i;
//		ptr = new int[i];
//	}
//	ABC(const ABC& obj) {
//		//if(strlen(this->ptr) >= strlen(obj.ptr))
//		ptr = new int[obj.len];
//		memcpy_s(ptr, sizeof(int)*len, obj.ptr, sizeof(int)*len);
//	}
//	ABC& operator=(const ABC& obj) {
//		/*if (this->len < obj.len) {
//			delete[] obj.ptr;
//			this->ptr = new int[obj.len];
//			this->len = obj.len;
//		}
//		memset(this->ptr, 0, sizeof(int)*len);
//		memcpy_s(ptr, sizeof(int)*len, obj.ptr, sizeof(int)*len);*/
//
//	}
//
//	friend ostream& operator<<(ostream&ob, const ABC& obj) {
////		ob << obj.a << " " << obj.b << endl;
//		return ob;
//	}
//
//};
//
//class Derived : public ABC {
//public:
//	Derived():ABC(6) {
//		cout << " Derived constr" << endl;
//	}
//	~Derived() {
//		cout << " Derived destr " << endl;
//	}
//};
//
//class mythreadArg {
//public:
//	bool istrue = false;
//};
//
//void threadFun(mythreadArg &j) {
//	while (!j.istrue) {
//		cout << " Not set " << " ";
//	}
//}
//void printAllPossibleWorldutils(char str[], char arr[], int count[], int len) {
//	if (strlen(str) == len)
//	{
//		cout << str << endl;
//		return;
//	}
//	for (int i = 1; i < strlen(arr); i++) {
//		if (count[i] == 0)
//			continue;
//		count[i]--;
//		str[i] = arr[i];
//		printAllPossibleWorldutils(str, arr, count, len + 1);
//		count[i]++;
//	}
//}
//void printAllPossibleWorld() {
//	map<int, string>MyMap;
//	int count[] = { 1,1,1 };
//	char str[] = { 0 };
//	char arr[] = "ABC";
//
//	printAllPossibleWorldutils(str, arr, count, 0);
//}
//int main() {
//
//	printAllPossibleWorld();
//
//	getchar();
//	return 0;
//}