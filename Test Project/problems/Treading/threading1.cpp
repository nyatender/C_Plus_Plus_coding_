

#include <vector>
#include <thread>
#include <iostream>
#include <memory>
#include <future>
#include <queue>
#include <set>
#include <condition_variable>
#include <unordered_set>
//#include <priority_queue>


using namespace std;

mutex mu;
queue<int>Q;
condition_variable cond;

int threadFun(std::shared_future<int>f) {
	int N = f.get();
	int res = 0;
	for (int i = 0; i < N;i++)
		res += i;

	return res;
}
list<int>Con;
void cosumer() {
	int data = 0;
	while (data != 1) {
		if (!Q.empty()) {
			data = Q.back();
			Q.pop();
			Con.push_back(data);
		}
		else
			std::chrono::microseconds(100);		
	}
}

void producer() {
	int i = 10;
	while (i > 0) {			
		Q.push(i);
		cout << " \nPushed " << i << endl;
		i--;
	}
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int Pivot(int arr[], int l, int n) {
	int s = l-1;
	int pivot = arr[n];

	for (int i = l; i <= n-1; i++) {
		if (pivot >= arr[i]) {
			s++;
			swap(&arr[s], &arr[i]);
		}
	}
	s++;
	swap(arr[s], arr[n]);
	return s;
}

void QuickSort(int arr[], int l, int high) {
	if (l < high) {
		int pivot = Pivot(arr, l, high);
		QuickSort(arr, l, pivot-1);
		QuickSort(arr, pivot+1, high);
	}
}

void sumOfTwo(int arr[], int sum, int i, int n) {
	for (int j = i + 1; j < n; j++) {
		if (arr[j] + arr[j + 1] == sum) {
		}
	}
}

void find3Numbers(int arr[], int N, int sum) {
	for (int i = 0; i < N; i++) {
		unordered_set<int>uSet;
		for (int j = i + 1; j < N; j++) {
			int x = sum-(arr[i] + arr[j]);
			if (uSet.find(x) != uSet.end()) {
				cout << arr[i] << " " << arr[j] << " " << sum - (arr[i] + arr[j]) << endl;
			}
			else {
				uSet.insert(arr[j]);
			}
		}
	}
}

void prinArr(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void Reheap(int arr[], int n, int parent) {
	int leftChild = 2 * parent + 1;
	int rightChild = 2 * parent + 2;

	int maxInndex = parent;

	if (leftChild < n  && arr[leftChild] > arr[maxInndex])
		maxInndex = leftChild;
	if (rightChild < n && arr[rightChild] > arr[maxInndex])
		maxInndex = rightChild;

	if (maxInndex != parent) {
		swap(&arr[maxInndex], &arr[parent]);
		Reheap(arr, n, maxInndex);
	}	
}

void HeapSort(int arr[], int n) {
	for (int i = (n / 2)-1; i >= 0; i--)  {
		Reheap(arr, n, i);
	}

	for (int i = n-1; i >= 0; i--) {
		cout << "\nBefore" << endl;
		prinArr(arr, n);
		swap(&arr[i], &arr[0]);
		Reheap(arr, i, 0);
		cout << "\nAfter" << endl;
		prinArr(arr, n);
	}
}

void sortK(int arr[], int N, int k) {

	priority_queue<int, vector<int>, greater<int>>pq(arr, arr + k + 1);
	int index = 0;
	for (int i = k+1; i < N; i++) {
		arr[index++] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}

	while (!pq.empty()) {
		arr[index++] = pq.top();
		pq.pop();
	}
}

typedef struct NODE {
	int data;
	NODE* left;
	NODE* right;
};

enum oparator {
	PLUS = 0,
	MINUS,
	MULTIPLY,
	DIVIDE
};

bool check(int data) {
	if (data == PLUS || 
		data == MINUS ||
		data == MULTIPLY ||
		data == DIVIDE)
		return true;

	return false;
}

int getCalculate(int a, int b, int op) {
	int res = 0;
	switch (op) 
	{
		case PLUS:
		{
			res = a + b;
			break;
		}
		case MINUS:
		{
			res = a - b;
			break;
		}
		case MULTIPLY:
		{
			res = a * b;
			break;
		}
		case DIVIDE:
		{
			res = a / b;
			break;
		}
		default:
			break;
	}

	return res;
}

//int EvaluteTree(NODE* root) {
//	if (root == NULL)
//		return;
//	if (check(root->data))
//	{
//		return getCalculate(EvaluteTree(root->left), EvaluteTree(root->right), root->data);
//	}
//	else
//		return root->data;
//}
mutex mu1;
condition_variable cond1[3];
void mythreadFunc(int i) {
	unique_lock<mutex>mu1(mu);
	cond1[i % 3].wait(mu1);
		cout << " console write " << i << endl;
	mu1.unlock();
	cond1[(i+1) % 3].notify_one();
}


class abc {
public:
	static int icount;
	static void increment() {
		++icount;
	}
};
int abc::icount;

int fun1() { return 10; }
char fun2() { return 'g'; }

class zC {
	int i;
};
class zB {
	int i;
};

int main1() {
	//zB zobj;
	//zC *c = static_cast<zC*>(&zobj);
	//zC c = (zC)zobj;

	thread arr[10];
	int n = 3;
	for (int i = 0; i < n; i++) {
		arr[i] = thread(mythreadFunc, i);
	}
	cond1[0].notify_one();
	for (int i = 0; i < n; i++)
		arr[i].join();

	int x = 5;

	// j will be of type int : data type of x 
	decltype(x) j = x + 5;

	cout << j << "  " << typeid(j).name() << endl;

	decltype(fun1()) x1 = 5;
	decltype(fun2()) y = 11;

	cout << x1 << "  " << typeid(x1).name() << endl;
	cout << y << "  " <<  typeid(y).name() << endl;
	
	//vector<int>vc{ 1,2,3,4 };
	//for_each(vc.begin(), vc.end(), [](int i) {cout << i;});


	//int arr[] = { 2, 6, 3, 12, 56, 8 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//int k = 3;
	//sortK(arr, n, k);
	//prinArr(arr, n);
	//thread t1(cosumer);
	//thread t2(producer);
	//t1.join();
	//t2.join();
	//cout << " Connsumed \n";
	//for (auto it = Con.begin(); it != Con.end(); it++) {
	//	cout << *it << " ";
	//}

	getchar();
	return 0;
}