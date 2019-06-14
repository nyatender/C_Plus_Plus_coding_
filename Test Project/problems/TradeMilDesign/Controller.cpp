
#include <iostream>
#include <thread>

using namespace std;

class Hardware {
public:
	void SetSpeed(double speed) {

	}

	void SetInclinatio() {

	}
	void Start() {

	}
	void Stop() {

	}
	void EmergencyStop() {

	}

	void HeartRateCensor() {

	}
};

class Controller {
public :
	Controller() {
		CusProg = new CustomProgram(2);
	}
	void SetCustomProgram(CustomProgram* CusProg) {
		if (CusProg != nullptr)
			delete CusProg;
		this->CusProg = CusProg;
	}

	void SetSpeed(double speed) {
		
	}

	void SetInclinatio() {

	}
	void Start() {
		CusProg->run();
	}
	void Stop() {

	}
	void EmergencyStop() {

	}

	void HeartRateCensor() {

	}
	static int HeartSpeed;
private:
	CustomProgram *CusProg;
	
};
int Controller::HeartSpeed = 0;

class CustomProgram {
	double Speed;
	double angle;
	double time;
public:

	CustomProgram(double anngel, double speed=5, double time=10) {
		this->angle = anngel;
		this->time = time;
		this->Speed = speed;
	}
	void SetSpeed(double speed) {
		this->Speed = speed;
	}
	void run() {
		int MaxSpeed = 0;
		thread t1(threadFun, Controller::HeartSpeed);
		t1.join();
	}
	void SetAngle(double angle) {
		this->angle = angle;
	}
	void SetTime(double time) {
		this->time = time;
	}
	static void threadFun(int heartRate) {

		//while(heartRate)
	}
};