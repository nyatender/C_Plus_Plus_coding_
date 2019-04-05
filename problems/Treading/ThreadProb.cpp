
#include <iostream>
#include <thread>
#include <map>
#include <vector>

using namespace std;

class Semaphore {
	int semaphore;
public:
	void InIt(int s) {
		semaphore = s;
	}

	void wait() {
		while (semaphore <= 0)
			continue;
		semaphore--;
	}
	void release() {
		semaphore++;
	}
};

map<int, char>m;

Semaphore hSem;
Semaphore oSem;
Semaphore BondSem;

Semaphore s;
vector<char>vec;
int icount = 0;
void printValue(vector<char>vec) {
	for (auto it = vec.begin(); it != vec.end(); it++)
		cout << *it;
	cout << endl;
}
void Bond(int id) {
	BondSem.wait();		
	icount++;
	if (icount == 3) {
		vec.push_back(m[id]);
		printValue(vec);
		vec.clear();
		while(icount-- > 0)
			s.release();
	}
	else {
		s.wait();
	}		
	BondSem.release();
}

void OxygenUtils(int id) {
	oSem.wait();
	Bond(id);
	oSem.release();
}

void HydrozenUtils(int id) {
	hSem.wait();
	Bond(id);
	hSem.release();
}

void Hydrozen() {
	int H = 1000;
	while (H) {
		if (H == 1050)
			break;
		HydrozenUtils(0);
		H++;
	}
}
void Oxygen() {

	int O = 5000;
	while (O ) {
		if (O == 5025)
			break;
		OxygenUtils(1);
		O++;
	}

}

int main() {

	hSem.InIt(2);
	oSem.InIt(1);
	BondSem.InIt(3);

	s.InIt(2);
	m[0] = 'H';
	m[1] = 'O';
	thread t1(Oxygen);
	thread t2(Hydrozen);

	t1.join();
	t2.join();

	return 0;
}

