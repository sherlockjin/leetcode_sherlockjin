#include"common.h"
using namespace std;

class Baidu{
public:
	int zhixian(int num, int timX, int timY, int** coordinates)
	{
		int res = 0;
		map<double, int> k;
		for (int i = 0; i < num; i++)
		{
			int tempX = coordinates[i][0] - timX;
			int tempY = coordinates[i][1] - timY;
			if (tempX != 0)
			{
				double tempK = (double)tempY / tempX;
				k[tempK] = 1;
			}
			else
			{
				double tempK = 0.0;
				k[tempK] = 1;
			}
			return k.size();

		}
	}

};
