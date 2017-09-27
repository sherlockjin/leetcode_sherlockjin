#include <iostream>
#include <string.h>
using namespace std;


//拷贝构造函数 和构造函数
class A
{
private:
	int* n;

public:
	A()
	{
		n = new int[10];
		n[0] = 1;
		cout << "constructor is called\n";
	}

	A(const A& a) //拷贝构造函数的参数一定是引用，不能不是引用，不然会出现无限递归
	{
		n = new int[10];
		memcpy(n, a.n, 10);  //通过按字节拷贝，将堆中一块内存存储到另一块内存
		cout << "copy constructor is called\n";
	}

	A operator=(const A& a)   //传参和返回值设置错误
	{
		if (this == &a)
			return *this;
		if (n != NULL)
		{
			delete n;
			n == NULL;
		}

		n = new int[10];
		memcpy(n, a.n, 10);
		cout << "assign constructor is called\n";
		return *this;
	}

	~A()
	{
		cout << "destructor is called\n";
		delete n;
	}

	void get()
	{
		cout << "n[0]: " << n[0] << endl;
	}
	

};

void arg(A a)
{
	cout << "arg : A" << endl;
}
A ret()
{
	A a;
	cout << "return : A" << endl;
	return a;
}
//int main()
//{
//	A a ;
//	//------------------------
//	 //A b(ret()); //ret返回的就是临时对象，直接b就是那个临时对象，不再调用拷贝构造函数或者赋值函数
//	//---------------------------
//	A b;
//	b = a;
//	//b = ret(); //ret()返回临时对象之后，进入赋值函数，
//				//正常情况下赋值函数的参数和返回值都是引用，所以不再调用拷贝构造函数，返回后把临时对象析构
//				//当参数不是引用，返回值是引用时，由于引用也是临时对象，故不再调用拷贝构造函数，与正常情况一样
//				//当返回值不是引用时，在返回值需要调用拷贝构造函数，之后析构掉这个和临时对象
//	b.get();
//
//	return 0;
//}




