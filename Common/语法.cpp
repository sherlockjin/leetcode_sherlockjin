#include"common.h"
#include<assert.h>
class CExample
{

	
public:
	int a;
	//���캯��
	CExample(){
		cout << "default constructor"  << endl;
	}
	CExample(int b)
	{
		a = b;
		cout << "constructor is called: " << a << endl;
	}
	//�������캯��
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

	//��������
	~CExample()
	{
		cout << "destructor is called: " << a << endl;
	}
	void Show()
	{
		cout << a << endl;
	}
};

//��ֹ��ֵ����
//class CExample
//{
//private:
//	int a;
//
//public:
//	//���캯��
//	CExample(int b)
//	{
//		a = b;
//		cout << "creat: " << a << endl;
//	}
//
//private:
//	//�������캯����ֻ������
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
	//arg_fun(A);   //��ֵ���ݽ�����
	ret_fun();
	A.Show();
	return 0;
}

/*
(1).A�������β�ʱ�����Ȼ����һ����ʱ�������ͽ� C �ɡ�
(2).Ȼ����ÿ������캯����A��ֵ��C�� ���������������е���CExample C(A);
(3).��g_fun()ִ�����, ������ C ����

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