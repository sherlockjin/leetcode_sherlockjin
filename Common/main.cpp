#include<iostream>
#include<algorithm>
using namespace std;

class Myclass
{
private:
	int Sum;    //������̬���ݳ�Ա
public:
	Myclass(){
		Sum = 4;
	}
	void GetSum()
	{
		cout << "Sum=" << Sum << endl;
	}
};
//const int Myclass::Sum = 3;       //���岢��ʼ����̬���ݳ�Ա

//void Myclass::GetSum()
//{
//	cout << "Sum=" << Sum << endl;
//}
//int main(void)
//{
//	Myclass me;
//	me.GetSum();
//	system("pause");
//	return 0;
//}
