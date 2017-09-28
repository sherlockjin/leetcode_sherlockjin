#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;

class A
{
	int _a;
public:
	A(int a) :_a(a)
	{

	}
	friend int f1(A&);
	friend int f2(const A&);
	friend int f3(A);
	friend int f4(const A);
};
//int main()
//{
//	A b(3);
//	
//	//f1(0);
//	f2(0);
//	f3(0);
//	f4(0);
//
//	return 0;
//}