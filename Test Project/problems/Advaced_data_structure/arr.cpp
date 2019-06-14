#include "arr.h"

#include <iostream>
#include <vector>

using namespace std;


int smallest(string arr) {
	int index = 0;
	int small = arr[0];
	for (int i = 1; i < arr.length(); i++) {
		if (small > arr[i]) {
			small = arr[i];
			index = i;
		}
	}
	return index;
}

void smallestNumUtils(string arr, int &s, int &e) {

	if (arr.length() == 1)
		return;

	int pos = smallest(arr);
	if (pos == 0) {
		s = s + 1;
		smallestNumUtils(arr.substr(1, arr.length()-1), s, e);
	}
	else {
		e = s + pos;
	}

	return;
}

void smallestNum(string arr) { //Minimum one swap to make number smaller possible.
	int start = 0;
	int end = 0;
	smallestNumUtils(arr, start, end);
	cout << arr[start] << "  " << arr[end] << endl;
}

void find(int rank[], int a, int b) {

}

typedef struct Parent {
	int parent;
	int rank;
};

int find(Parent visited[], int a) {
	if (visited[a].parent != a)
		visited[a].parent = find(visited, visited[a].parent);

	return visited[a].parent;
}

void Union(Parent visited[], int a, int b) {
	int x = find(visited, a);
	int y = find(visited, b);

	if (visited[x].rank > visited[y].rank) {
		visited[y].parent = x;
	}
	else if (visited[x].rank < visited[y].rank)
		visited[x].parent = y;
	else {
		visited[y].parent = x;
		visited[x].rank++;
	}
}

void countNoOfCycleUtils(int arr[], Parent visited[], int &count, int i, int s) {
	int x = find(visited, i);
	int y = find(visited, s);
	if (x != y) {
		count++;
	}
}

void countNoOfCycleUtils(int arr[], bool visited[], Parent subset[], int &count, int i, int s) {
	if (!visited[i]) {
		visited[i] = true;
		return countNoOfCycleUtils(arr, visited, subset, count, arr[i], i);
	}
	else if (visited[i] == true) {
		if (arr[s] == i) {
			int x = find(subset, arr[s]);
			int y = find(subset, s);
			if (x != y) {
				count++;
				Union(subset, i, s);
			}
		}
		return;
	}
}

void conchange(int arr[], int n) {

}

int countNoOfCycle(int arr[], int n) {
	int count = 0;
	Parent *subset = new Parent[n];
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		subset[i].parent = i;
		subset[i].rank = 0;
	}
	for (int i = 0; i < n; i++) {
		countNoOfCycleUtils(arr, visited, subset, count, i, i);
	}
	for (int i = 0; i < n; i++)
		if (arr[i] == i)
			count++;

	return count;
}

void swap(string &s, int i, int j) {
	char t = s[i];
	s[i] = s[j];
	s[j] = t;
}

void permutationOfString(string str, int s, int end) {

	if (s == end) {
		cout << str.c_str() << endl;
		return;
	}
	for (int i = s; i < str.length(); i++) {
		swap(str, s, i);
		permutationOfString(str, s + 1, end);
		swap(str, s, i);
	}

}

int longestPalindromicSequenceRecUtils(string str, int mid, int low, int high) {

	if (mid == low)
		return 0;


}

int longestPalindromicSequenceRec(string str) {

	return longestPalindromicSequenceRecUtils(str, 0, str.length());

}

int max(int a, int b) {
	return (a > b ? a : b);
}

int longestPalidSubsequence(string str, int i, int j) {

	if (i == j)
		return 1;

	if (str[i] == str[j] && i + 1 == j)
		return 2;

	if (str[i] == str[j]) 
		return longestPalidSubsequence(str, i + 1, j - 1) + 2;
	
	return max(longestPalidSubsequence(str, i + 1, j), longestPalidSubsequence(str, i, j - 1));
}

int longestPalidSubsequenceDp(string str, int i, int j) {

	int n = str.length();
	bool **table = new bool*[n + 1];

	for (int i = 0; i < n; i++) {
		table[i] = new bool[n + 1]{ 0 };
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < n-i; j++) {
			int l = i + j - 1;
			if (str[i] == str[j] && i == 2) {
				table[i][j] = 2;
			}
			else if (str[i] == str[j]) {
				table[i][j] = table[i + 1][j - 1] + 2;
			}
			else {
				table[i][j] = max(table[i + 1][j], table[i][j - 1]);
			}
		}
	}

	return 0;
}

void longestPalindromicSequence(string str) {

	int n = str.length();
	bool **table = new bool*[n+1];

	for (int i = 0; i < n; i++) {
		table[i] = new bool[n + 1]{ 0 };
	}

	int maxLen = 1;
	int start = 0;
	for (int i = 0; i < n; i++) {
		table[i][i] = true;
	}

	for (int i = 0; i < n-1; i++) {
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			maxLen = 2;
			start = i;
		}
	}

	for (int i = 3; i <= n; i++) {
		for (int j = 0; j < n - i + 1; j++) {
			int l = i + j - 1; //Last index
			if (str[i] == str[j] && table[i + 1][j - 1] == true) {
				table[i][j] = true;
				maxLen = i;
				start = j;
			}
		}
	}
}

int main() {
	//string arr = "26475";
	//smallestNum(arr);
	//int arr[] = {2, 3, 1, 1, 2, 0};
	int arr[] = { 2, 3, 0, 1, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	//cout << countNoOfCycle(arr, n);
	string str = "ABCD";
	//permutationOfString(str, 0, str.length()-1);
	string palin = "adsgeeksforgeeksaabbaa";
	longestPalindromicSequence(palin);

	getchar();

	return 0;
}
