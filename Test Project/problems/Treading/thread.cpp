

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mu;
condition_variable *cond;

void TreadFun(int i, const int& N) {
	std::unique_lock<mutex>uLock(mu);
	cond[i%N].wait(uLock); // , []() {return N > 0;}
	cout << " delete file by thread " << i+1 << endl;
	uLock.unlock();
	cond[(i+1)%N].notify_one();
}

int main() {
	int N;
	cout << " Enter no of thread ";
	cin >> N;
	vector<thread>T;
	cond = new condition_variable[N];

	for (int i = 0; i < N; i++) {
		T.push_back(thread(TreadFun, i, ref(N)));
	}
	cond[0].notify_one();
	for (int i = 0; i < N; i++) {
		T[i].join();
	}

	getchar();
	getchar();
	return 0;
}