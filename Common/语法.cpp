#include"common.h"
#include<assert.h>
class CExample
{

	
public:
	int a;
	//构造函数
	CExample(){
		cout << "default constructor"  << endl;
	}
	CExample(int b)
	{
		a = b;
		cout << "constructor is called: " << a << endl;
	}
	//拷贝构造函数
	CExample(const CExample& A)
	{
		a = A.a;
		cout << "copy constructor is called: " << a << endl;
		
	}
	/*CExample operator=(const CExample& A)
	{
		CExample B(A);
		printf("fuzhi is called\n");
		return B;
	}*/

	//析构函数
	~CExample()
	{
		cout << "destructor is called: " << a << endl;
	}
	void Show()
	{
		cout << a << endl;
	}
};

//防止按值传递
//class CExample
//{
//private:
//	int a;
//
//public:
//	//构造函数
//	CExample(int b)
//	{
//		a = b;
//		cout << "creat: " << a << endl;
//	}
//
//private:
//	//拷贝构造函数，只是声明
//	CExample(const CExample& C);
//
//public:
//	~CExample()
//	{
//		cout << "delete: " << a << endl;
//	}
//
//	void Show()
//	{
//		cout << a << endl;
//	}
//};


void arg_fun(CExample C)
{
	cout << "arg : CExample" << endl;
}
CExample ret_fun()
{
	CExample temp(19);
	cout << "return : CExample" << endl;
	return temp;
}
int main()
{
	CExample A(1);
	//arg_fun(A);   //按值传递将出错
	ret_fun();
	A.Show();
	return 0;
}

/*
(1).A对象传入形参时，会先会产生一个临时变量，就叫 C 吧。
(2).然后调用拷贝构造函数把A的值给C。 整个这两个步骤有点像：CExample C(A);
(3).等g_fun()执行完后, 析构掉 C 对象。

*/





//int main()
//{
//	CExample A(100);
//	arg_fun(A);
//	ret_fun();
//	A.Show();
//	//B.Show();
//	return 0;
//}

class Rect
{
public:
	Rect()
	{
		p = new int[100];
		for (int i = 0; i < 100; i++)
		{
			p[i] = i;
		}
	}
	Rect(const Rect& r)
	{
		width = r.width;
		height = r.height;
		p = new int[100];
		*p = *(r.p);
		/*for (int i = 0; i < 100; i++)
		{
			p[i] = r.p[i];
		}*/

	}
	~Rect()
	{
		assert(p != NULL);
		delete p;
	}


	int width;
	int height;
	int *p;
};


//int main()
//{
//	Rect rect1;
//	Rect rect2(rect1);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << rect2.p[i];
//	}
//	return 0;
//}