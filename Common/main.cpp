#include<iostream>
#include<algorithm>
using namespace std;

class Myclass
{
private:
	int Sum;    //声明静态数据成员
public:
	Myclass(){
		Sum = 4;
	}
	void GetSum()
	{
		cout << "Sum=" << Sum << endl;
	}
};
//const int Myclass::Sum = 3;       //定义并初始化静态数据成员

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
