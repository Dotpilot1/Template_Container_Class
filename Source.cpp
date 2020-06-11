#include <iostream>     
#include <iomanip>      
#include <string>

#include "Vector.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;


int main()
{
	

	Vector<int> v1(10, 5);
	Vector<char> v2(10, 'a');
	//MyVector<int> v1{10, 5};  // mantik hatasina neden olabilir!!!
	//MyVector<char> v2{10, 'a'};
	Vector<int> v3{ 1, 2, 3, 4, 5, 6, 7, 56, 54, 34, 38, 768 };

	Vector<int> v4;

	v4 += v3;
	v4 += v3;

	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;
	cout << "v3: " << v3 << endl;
	cout << "v4: " << v4 << endl;

	

	Queue<int> q1;
	Queue<int> q2{ 1, 2, 3, 4, 5, 6, 7, 56, 54, 34, 768 };
	Queue<int> q3 = v4;
	Queue<int> q4{ v4 };

	cout << "q1: " << q1 << endl;
	cout << "q2: " << q2 << endl;
	cout << "q3: " << q3 << endl;
	cout << "q4: " << q4 << endl;


	while (q3.getSize() > 0)
		cout << "q3 pop: " << q3.pop() << " --> q3: " << q3 << endl;


	

	while (q3.getSize() < 10)
	{
		q3.push(q3.getSize() * 5);
		cout << "q3: " << q3 << endl;
	}

	

	while (q3.getSize() > 0)
		cout << "q3 pop: " << q3.pop() << " --> q3: " << q3 << endl;



	Stack<int> s1;
	Stack<int> s2{ 1, 2, 3, 4, 5, 6, 7, 56, 54, 34, 768 };
	Stack<int> s3 = v4;
	Stack<int> s4{ v4 };

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;



	while (s3.getSize() > 0)
		cout << "s3 pop: " << s3.pop() << " --> s3: " << s3 << endl;




	while (s3.getSize() < 10)
	{
		s3.push(s3.getSize() * 5);
		cout << "s3: " << s3 << endl;
	}

	

	while (s3.getSize() > 0)
		cout << "s3 pop: " << s3.pop() << " --> s3: " << s3 << endl;

	return 0;
}