#include "common.h"
#include"binary_search.cpp"
#include<stdint.h>
int main()
{
	/*BinarySearch b;
	b.test();
	cout << "hello" << endl;
	return 0;*/
	float number = 1;
	union{ float f; unsigned int u; } x;
	x.f = number;
	x.u = 0x80000000 ^ x.u;
	cout << x.f;

}