	#include "Queue.h"
	using namespace std;
	int main()
	{
		Queue <int> queue = Queue <int>();
		queue.push(1);
		queue.push(2);
		queue.push(3);
		queue.push(4);
		cout << queue.front();
	}