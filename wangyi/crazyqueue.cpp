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

		//minIndex和maxIndex指示排序后计算疯狂值前的队列
		//minValue和maxValue指示计算疯狂值后的队列
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
		//为奇数的时候
		if (minIndex == maxIndex){
			crazyValue += max(maxValue - h[minIndex], h[maxIndex] - minValue);
		}
		cout << crazyValue << endl;
	}
};



