#include <iostream>
#include <string>
#include "queue.cpp"
int main()
{
	using std::cout;
	using std::string;
	Queue<int> intq;
	Queue<float> floatq(50);
	Queue<string> strq;
	Queue<double> doubleq(100);
	cout << "filling intq\n";
	int ints[5] = {1,2,3,4,5};
	for (int i = 0; i<5; i++)
		intq.enqueue(ints[i]);
	int curint;
	while (intq.dequeue(curint))
	{
		cout << "dequeued from intq: " << curint << "\n";	
	}
	cout << "filling floatq\n";
	float floats[3] = {5.0, 100.0, 1000.0};
	for (int i = 0; i<3; i++)
		floatq.enqueue(floats[i]);
	float curfl;
	cout << "pos 2 of floatq: " << floatq[2] << "\n";
	//curfl = floatq[5]; //segfaults
	cout << "filling string queue\n";
	string strings[4] = {"uh","oh","woops","broke it"};
	for (int i = 0; i<4; i++)
		strq.enqueue(strings[i]);
	string curst;
	while (strq.dequeue(curst))
	{
		cout << "dequeued from strq: " << curst << "\n";
	}
	return 0;
}		
