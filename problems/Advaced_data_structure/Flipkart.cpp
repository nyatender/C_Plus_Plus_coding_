

#include <iostream>

using namespace std;

char digitArr[10][5] = { "", "", "abc", "def","ghi", "jkl","mno","pqrs","tuv","wxyz" };

void printStringUtils(char output[], int digit_ind, char inputArray[], int n) {
	if (n == digit_ind)
	{
		cout << output << endl;
		return;
	}

	for (int i = 0; i < strlen(inputArray); i++) {
		output[digit_ind] = digitArr[inputArray[digit_ind]][i];
		printStringUtils(output, digit_ind + 1, inputArray, n);
		if (inputArray[digit_ind] == 1 || inputArray[digit_ind] == 2)
			return;
	}
}

void printString(int arr[], int n) {

	char *result = new char[n];


}

int max(int a, int b) {
	return (a > b ? a : b);
}

int stockBuyAndSell(int arr[], int n, int k) {

	int **table = new int*[n + 1]();
	for (int i = 0; i <= k;i++)
		table[i] = new int[n + 1]();
	int i = 0, j = 0;
	for (i = 1; i <= k;i++) {
		for (j = 1;j < n;j++) {
			int max_so_far = INT_MIN;
			for (int x = 0; x < n;j++) {
				max_so_far = max(max_so_far, (arr[j] - arr[x]) + table[i - 1][x]);
			}
			table[i][j] = max(max_so_far, table[i][j-1]);
		}
	}

	return table[i][j];
}

void print(char output[], int len) {
	while(len-- > 0)
		cout << output << endl;
}
void combination(char input[], int count[], char output[], int pos, int len) {
	print(output, len);	
	for (int i = pos; i <= strlen(input); i++) {
		if (count[i] == 0)
			continue;
		output[len] = input[i];
		count[i]--;
		combination(input, count, output, i, len + 1);
		count[i]++;
	}
}

void combination(char input[]) {
	int count[] = { 1,1,1 };
	char *output = new char[strlen(input)];
	combination(input, count, output, 0, 0);
}

void swap(char arr[], int i, int j) {
	char h = arr[i];
	arr[i] = arr[j];
	arr[j] = h;
}

void AllPermutation(char arr[], int s, int e) {

	if (s == e) {
		cout << arr << endl;
		return;
	}

	for (int i = s; i < e; i++) {
		swap(arr, s, i);
		AllPermutation(arr, s + 1, e);
		swap(arr, s, i);
	}

}

class abc {
private:
	virtual void fun() {
		cout << " hi " << endl;
	}
};
class x : public abc {
	void fun() {
		cout << " in X " << endl;
	}
};

int main2() {
	abc *p = new x;
	//p->fun();
	/*int digit[] = { 2,3,4 };
	int n = sizeof(digit) / sizeof(digit[0]);
	printString(digit, n);*/
	char input[] = "ABC";
	//combination(input);
	AllPermutation(input, 0, strlen(input));

	getchar();
	return 0;
}