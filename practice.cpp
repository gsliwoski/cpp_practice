#include <iostream>
#include <string>
#include "queue.cpp"
#include "stack.cpp"
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
	cout << "inverting string queue\n";
	strq.invert();
	while (strq.dequeue(curst))
	{
		cout << "dequeued from strq: " << curst << "\n";
	}
	
	cout << "\n----Stack----\n";
	Stack<int> intst(3);
	Stack<string> strs;
	cout << "filling int stack (up to 3)\n";
	for (int i=0; i<5; i++)
		intst.push(ints[i]);
	cout << "filling string stack\n";
	for (int i=0; i<4; i++)
		strs.push(strings[i]);
	cout << "popping int stack\n";	
	while (intst.pop(curint))
		cout << "popped " << curint << "\n";
	cout << "popping string stack\n";
	while (strs.pop(curst))
		cout << "popped " << curst << "\n";
	
	return 0;
}		
