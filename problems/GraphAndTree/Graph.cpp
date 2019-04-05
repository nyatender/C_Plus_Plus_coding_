

#include <iostream>

using namespace std;

#define V 5

void primMST(int G[][V]) {
	int *visit = new int[V];
	int *path = new int[V];
}

class abc {
private:
	int *a;
public:
	abc() {
		cout << " out " << endl;
	}
	void fun() {

	}
	//void operator new(size_t n) {

	//}
};

int main()
{
	/* Let us create the following graph
			2 3
		(0)--(1)--(2)
		| / \ |
		6| 8/ \5 |7
		| /     \ |
		(3)-------(4)
				9         */
	int graph[V][V] = { {0, 2, 0, 6, 0},
						{2, 0, 3, 8, 5},
						{0, 3, 0, 0, 7},
						{6, 8, 0, 0, 9},
						{0, 5, 7, 9, 0} };

	// Print the solution 
	primMST(graph);

	getchar();

	return 0;
}