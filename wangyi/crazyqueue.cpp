#include"common.h"

class CrazyValue{
public:
	void calcCrazyValue(){
		int n;
		int h[55];
		int crazyValue;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> h[i];
		}
		sort(h, h + n);

		//minIndex��maxIndexָʾ����������ֵǰ�Ķ���
		//minValue��maxValueָʾ������ֵ��Ķ���
		int minIndex = 0;
		int maxIndex = n - 1;
		int minValue = h[minIndex];
		int maxValue = h[maxIndex];
		crazyValue = maxValue - minValue;

		minIndex++;
		maxIndex--;
		while (minIndex < maxIndex){
			crazyValue += maxValue - h[minIndex];
			crazyValue += h[maxIndex] - minValue;
			maxValue = h[maxIndex--];
			minValue = h[minIndex++];
		}
		//Ϊ������ʱ��
		if (minIndex == maxIndex){
			crazyValue += max(maxValue - h[minIndex], h[maxIndex] - minValue);
		}
		cout << crazyValue << endl;
	}
};



