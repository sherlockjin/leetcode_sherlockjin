#include <iostream>
#include <string.h>
using namespace std;


//�������캯�� �͹��캯��
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

	A(const A& a) //�������캯���Ĳ���һ�������ã����ܲ������ã���Ȼ��������޵ݹ�
	{
		n = new int[10];
		memcpy(n, a.n, 10);  //ͨ�����ֽڿ�����������һ���ڴ�洢����һ���ڴ�
		cout << "copy constructor is called\n";
	}

	A operator=(const A& a)   //���κͷ���ֵ���ô���
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
//	 //A b(ret()); //ret���صľ�����ʱ����ֱ��b�����Ǹ���ʱ���󣬲��ٵ��ÿ������캯�����߸�ֵ����
//	//---------------------------
//	A b;
//	b = a;
//	//b = ret(); //ret()������ʱ����֮�󣬽��븳ֵ������
//				//��������¸�ֵ�����Ĳ����ͷ���ֵ�������ã����Բ��ٵ��ÿ������캯�������غ����ʱ��������
//				//�������������ã�����ֵ������ʱ����������Ҳ����ʱ���󣬹ʲ��ٵ��ÿ������캯�������������һ��
//				//������ֵ��������ʱ���ڷ���ֵ��Ҫ���ÿ������캯����֮���������������ʱ����
//	b.get();
//
//	return 0;
//}




