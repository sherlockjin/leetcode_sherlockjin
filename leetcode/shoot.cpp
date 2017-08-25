#include"common.h"

int store[10];//存储每次的得分

//打把num次，得分为score的可能次数

int comput(int score, int num)
{
	int count = 0;
	if (score < 0 || num * 10 < score){
		return 0;
	}
	if (num == 1)
	{
		store[num - 1] = score;
		for (int i = 1; i >= 0; i--){
			cout << store[i] << " ";
		}
		cout << endl;
		return 1;

	}
	for (int i = 0; i <= 10; i++){
		store[num - 1] = i;
		count += comput(score - i, num - 1);
	}
	return count;
}
//int main(){
//	int sum = comput(3, 2);
//	cout << sum << endl;
//}