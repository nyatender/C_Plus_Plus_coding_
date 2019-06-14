
//
//#include <iostream>
//#include <string>
//#include <map>
//
//using namespace std;
//static int N;
//class abc {
//public:
//	int i;
//	string a;
//	string b;
//	abc(string a, string b) {
//		i = 0;
//		this->a = a;
//		this->b = b;
//	}
//
//	bool operator<(const abc& obj) const {
//		int l = _stricmp(this->a.c_str(), obj.a.c_str());
//		if (l > 0)
//			return true;
//
//		return false;
//	}
//
//}
//bool compare(abc obj1, abc obj2) {
//	if (obj1.i > obj2.i)
//		return true;
//
//	return false;
//}

//int main() {
//	
//	map<abc, int>m_UserInfoMap;
//	m_UserInfoMap.insert(std::make_pair<abc, int>(abc("Mr.X", "3"), 100));
//	m_UserInfoMap.insert(std::make_pair<abc, int>(abc("Mr.X", "1"), 120));
//	m_UserInfoMap.insert(std::make_pair<abc, int>(abc("Mr.Z", "2"), 300));
//	return 0;
//}