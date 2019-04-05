//#include <iostream>
//#include <queue>
//#include <list>
//
//using namespace std;
//
//class annimal {};
//class annimalDrive: public annimal {};
//
////class base {};
//
//int snakeLadder(int arr[], int n) {
//
//	typedef struct Query {
//		int v;
//		int distance;
//	};
//	bool *visited = new bool[n];
//	for (int i = 0; i < n; i++) {
//		visited[i] = false;
//	}
//	Query q{ 0, 0 };
//	list<Query> Q;
//	Q.push_back(q);
//	visited[0] = true;
//	Query u;
//	while (!Q.empty()) {
//		u = Q.front();
//		Q.pop_front();
//		if (u.v == n)
//			break;
//		for (int i = u.v; i < (u.v + 6) && i < n; i++) {
//			if (!visited[i]) {
//				visited[i] = true;
//				Query nD;
//				nD.distance = u.distance + 1;
//				if (arr[u.v] == -1)
//					nD.v = i;
//				else
//					nD.v = arr[i];
//				Q.push_back(u);
//			}
//		}
//	}
//
//	return u.distance;
//}
//
//void patternMatch(string a, string b) {
//	string str = a + "$" + b;
//	int n = str.length();
//
//	int *z = new int[n];
//
//	int l = 0, r = 0;
//
//	for (int i = 1; i < n; i++) {
//		if (r < i) {
//			l = r = i;
//			while (r < n && str[r] == str[r - l])
//				r++;
//			z[i] = r - l;
//			r--;
//		}
//		else {
//			int k = i - l;
//			if (str[k] < r - i + 1)
//				z[i] = z[k];
//			else {
//				l = i;
//				while (r < n && str[r] == str[r - l])
//					r++;
//				z[i] = r - l;
//				r--;
//			}
//		}
//	}
//}
//
//bool disconaryContain(string s) {
//	return true;
//}
//
//bool wordBreak(string str) {
//
//	int n = str.size();
//
//	if (n == 0)
//		return true;
//
//	for (int i = 1; i < n; i++) {
//
//		if (disconaryContain(str.substr(0, i)) && wordBreak(str.substr(i, n - 1)))
//			return true;
//	}
//
//}
//
//bool wordBreakDP(string str) {
//
//	int n = str.length();
//	bool *wb = new bool[n+1] {0};
//
//	for (int i = 1; i <= n; i++) {
//
//		if(wb[i] == false && disconaryContain(str.substr(0, i)))
//			wb[i] = true;
//
//		if (wb[i] == true) {
//			for (int j = i + 1; j <= n; j++) {
//				if (wb[j] == false && disconaryContain(str.substr(i, j)))
//					wb[j] = true;
//
//				if (j == n && wb[j] == true)
//					return true;
//			}
//		}			   
//	}
//
//	return true;
//}
//
//
//class base {
//	int i;
//private :
//	static base* instance;
//	int size;
//	base *p;
//
//	void* operator new(rsize_t size);
//public:
//	static base* getinstance() {
//		if (instance == NULL) {
//			instance = new base();
//		}
//		return instance;
//	}
//	base& operator[](int i) {
//		if (i >= size) {
//			throw;
//		}
//		return p[i];
//	}
//	base() {
//		cout << " i base const " << endl;
//	}
//	~base() {
//		cout << " i base destr " << endl;
//	}
//
//	/*void* operator new(rsize_t size) {
//		base* p = ::new base();
//		return p;
//	}*/
//
//	void operator delete(void* p) {
//		free(p);
//	}
//};
//class derived : public base {
//
//};
//
//int main() {
//
//	string s = "yaten";
//	cout << s.substr(0, 1).c_str();
//
////	base arr1[100];
//	//base *p = new base();
//	//delete p;
//	//derived *d = static_cast<derived*>(new base());
//	base arr[7];
//	annimal obj1;
//	annimalDrive *obj7 = static_cast<annimalDrive*>(&obj1);
//	annimal obj2 = (annimal)obj1;
//	annimal obj3 = static_cast<annimal>(obj1);
//	//base *obj4 = static_cast<base*>(&obj1);
//	base *obj5 = (base*)(&obj1);
//	base *obj6 = (base*)(&obj1);
//
//	int i = 10;
//	double d = (double)i;                  //C-style cast
//	double d2 = static_cast<double>(i);  //C++ cast
//
//	cout << "Hello";
//
//	getchar();
//	return 0;
//}