//
//
//#include <iostream>
//
//using namespace std;
//
//void buildZarray(int ZArr[], int l) {
//
//	int left = 0, right = 0;
//
//	for (int i = 1; i < l; i++) {
//		if (i > right) {
//			left = right = i;
//			while (right < l && ZArr[right] == ZArr[right - left])
//				right++;
//			ZArr[i] = ZArr[right-left];
//			right--;
//		}
//		else {
//			int k1 = i - left;
//			if (ZArr[k1] < right - i + 1)
//				ZArr[i] = ZArr[k1];
//			else {
//				left = i;
//				while (right < l && ZArr[right] == ZArr[right - left])
//					right++;
//				ZArr[i] = ZArr[right - left];
//				right--;
//			}
//		}
//	}
//
//}
//
//void search(string text, string pat) {
//
//	string zString = pat + "$" + text;
//	int ZLen = zString.length();
//	int *ZArr = new int[ZLen];
//
//	buildZarray(ZArr, ZLen);
//}
//
//// Driver program 
//int main()
//{
//	string text = "GEEKS FOR GEEKS";
//	string pattern = "GEEK";
//	search(text, pattern);
//	return 0;
//}