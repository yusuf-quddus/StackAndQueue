// CIS 22C #02Y
// Shows functionality of stack and queue ADT
// Yusuf Quddus

/*
Program Code (Pseudocode):
	>Prints a stack string list
	>Pushes strings into the list
	>Deletes 3 top string values and prints the list
	>Deletes another 3 top string values and prints the list
	>Empties the List and reprints it
	>Prints a stack rupee list
	>Pushes rupees into the list
	>Deletes 3 top rupee values and prints the list
	>Empties the List and reprints it
	>Prints a queue int list
	>Queues rupees into the list
	>deQueues 3 int values and prints the list
	>deQueues another 3 int values and prints the list
	>Empties the List and reprints it
	>Prints a queue rupee list
	>deQueues 3 rupee values and prints the list
	>Empties the List and reprints it
	>Program exits
*/

#include <iostream>
#include <string>
#include "List.h"
#include "LinkNode.h"
#include "Stack.h"
#include "Queue.h"
#include "Currency.h"

using namespace std;

void divider();

int main() {

	Rupee rData[20];
	for (int i = 0; i <= 19; i++) {
		rData[i].setWholePart(i);
		rData[i].setFractionalPart(i);
	}

	divider();

	Stack<string> S("baskets");
	S.push("of");
	S.push("fruit");
	S.push("makes");
	S.push("me");
	S.push("eat");
	S.push("my");
	S.push("pants");
	S.push("foo");
	S.push("bar");

	cout << "STACK STRING LIST" << endl;
	S.printData();
	cout << endl;

	cout << endl << "Top value is " << S.peek() << endl;
	cout << "popping top value" << endl;
	S.pop();
	cout << endl << "Top value is " << S.peek() << endl;
	cout << "popping top value" << endl;
	S.pop();
	cout << endl << "Top value is " << S.peek() << endl;
	cout << "popping top value" << endl;
	S.pop();


	cout << endl << "NEW STACK STRING LIST" << endl;
	S.printData();
	cout << "count:" << S.getCount() << endl;

	cout << endl << "Top value is " << S.peek() << endl;
	cout << "popping top value" << endl;
	S.pop();
	cout << endl << "Top value is " << S.peek() << endl;
	cout << "popping top value" << endl;
	S.pop();
	cout << endl << "Top value is " << S.peek() << endl;
	cout << "popping top value" << endl;
	S.pop();

	cout << endl << "NEW STACK STRING LIST" << endl;
	S.printData();
	cout << "count:" << S.getCount() << endl;

	cout << endl << "NEW STACK STRING LIST" << endl;
	cout << "Emptying List . . ." << endl;
	S.empty();
	S.printData();
	cout << "count:" << S.getCount() << endl;


	divider();


	Stack<Rupee> R(rData[9]);

	R.push(rData[4]);
	R.push(rData[1]);
	R.push(rData[3]);
	R.push(rData[2]);
	R.push(rData[6]);
	R.push(rData[13]);
	R.push(rData[9]);
	R.push(rData[17]);
	R.push(rData[7]);
	R.push(rData[9]);

	cout << "STACK RUPEE LIST" << endl;
	R.printData();
	cout << "Count: " << R.getCount() << endl << endl;


	cout << endl << "Top value is " << R.peek() << endl;
	cout << "popping top value" << endl;
	R.pop();
	cout << endl << "Top value is " << R.peek() << endl;
	cout << "popping top value" << endl;
	R.pop();
	cout << endl << "Top value is " << R.peek() << endl;
	cout << "popping top value" << endl;
	R.pop();


	cout << endl << "NEW STACK RUPEE LIST" << endl;
	R.printData();
	cout << "Count: " << R.getCount() << endl << endl;


	cout << "Emptying list . . ." << endl;
	R.empty();
	R.printData();
	cout << "Count: " << R.getCount() << endl << endl;


	divider();


	Queue<int> Q(4);
	Q.enQueue(5);
	Q.enQueue(7);
	Q.enQueue(9);
	Q.enQueue(11);
	Q.enQueue(1);
	Q.enQueue(30);
	Q.enQueue(6);
	Q.enQueue(7);
	Q.enQueue(3);


	cout << "QUEUE INT LIST" << endl;
	Q.printData();
	cout << endl;

	cout << endl << "Front value is " << Q.Front() << endl;
	cout << "queueing front value" << endl;
	Q.deQueue();
	cout << endl << "Front value is " << Q.Front() << endl;
	cout << "queueing front value" << endl;
	Q.deQueue();
	cout << endl << "Front value is " << Q.Front() << endl;
	cout << "queueing front value" << endl;
	Q.deQueue();


	cout << endl << "NEW QUEUE STRING LIST" << endl;
	Q.printData();
	cout << "count:" << Q.getCount() << endl;

	cout << endl << "Front value is " << Q.Front() << endl;
	cout << "queueing front value" << endl;
	Q.deQueue();
	cout << endl << "Front value is " << Q.Front() << endl;
	cout << "queueing front value" << endl;
	Q.deQueue();
	cout << endl << "Front value is " << Q.Front() << endl;
	cout << "queueing front value" << endl;
	Q.deQueue();

	cout << endl << "NEW QUEUE STRING LIST" << endl;
	Q.printData();
	cout << "count:" << Q.getCount() << endl;

	cout << endl << "NEW QUEUE STRING LIST" << endl;
	cout << "Emptying List . . ." << endl;
	Q.empty();
	Q.printData();
	cout << "count:" << Q.getCount() << endl;


	divider();


	Queue<Rupee> qR(rData[9]);

	qR.enQueue(rData[4]);
	qR.enQueue(rData[1]);
	qR.enQueue(rData[3]);
	qR.enQueue(rData[2]);
	qR.enQueue(rData[6]);
	qR.enQueue(rData[13]);
	qR.enQueue(rData[9]);
	qR.enQueue(rData[17]);
	qR.enQueue(rData[7]);
	qR.enQueue(rData[9]);

	cout << "QUEUE RUPEE LIST" << endl;
	qR.printData();
	cout << "Count: " << qR.getCount() << endl << endl;


	cout << endl << "Front value is " << qR.Front() << endl;
	cout << "queueing front value" << endl;
	qR.deQueue();
	cout << endl << "Front value is " << qR.Front() << endl;
	cout << "queueing front value" << endl;
	qR.deQueue();
	cout << endl << "Front value is " << qR.Front() << endl;
	cout << "queueing front value" << endl;
	qR.deQueue();


	cout << endl << "NEW QUEUE RUPEE LIST" << endl;
	qR.printData();
	cout << "Count: " << qR.getCount() << endl << endl;


	cout << "Emptying list . . ." << endl;
	qR.empty();
	qR.printData();
	cout << "Count: " << qR.getCount() << endl << endl;


	divider();


	system("pause");
	return 0;
}

/*************************************************************
divider
prints a divider
pre:
post: prints a divider
return: void
*************************************************************/
void divider()
{
	cout << "\n\n=======================================\n\n";
}