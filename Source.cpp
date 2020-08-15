#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{


	Vector v1(2); 
	v1.pushBack(10);
	v1.pushBack(20);
	cout << "The size of v is " << v1.size() << endl; 
	cout << "The capacity of v is " << v1.capacity() << endl; 
	

	v1.print(); 
	if (!v1.empty())
		v1.popBack(); 
	v1.print();
	cout << "The size of v is " << v1.size() << endl; 

	v1.reserve(20); 
	v1.front() = 1234; 
	v1.clear();
	cout << "The size of v after clearing is " << v1.size() << endl; 

	v1.pushBack(1);
	v1.pushBack(2);
	v1.pushBack(3);




	Vector v2(4, -1); 
	v2[1] = 20; 
	Vector v3 = v1 + v2; 
	v3.insert(333, 2);
	cout << "v3 is " << v3 << endl; 

	v3 = v1 * 5;  
	cout << "v3 is \t" << v3 << endl;  

	v2 *= 10; 

	v2 += Vector(3, 5); 



	system("pause");
	return 0;
}