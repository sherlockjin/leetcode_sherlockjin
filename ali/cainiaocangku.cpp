#include"common.h"

class Cangku{
public:
	int Get1(int n){
		int s = 0;
		int a = 0;
		// do something
		//i 为第几行
		int i = 0;
		int th = 10;
		int length = 1;
		do{
			i++;
			if (i >= th) {
				th *= 10;
				length++;
			}
			a += length;
			s += a;
		} while (s < n);

		int y = n - (s-a);

		//在第i行，第n-(s-a)即第y个,从1开始数
		/*cout << i << endl;
		cout << y << endl;*/
		
		//长度相同的为一组
		int z = 0;
		int len = 0;
		do{
			len++;
			z += len * (pow(10, len) - pow(10, len - 1));
		} while (z < y);
		z -= len * (pow(10, len) - pow(10, len - 1));

		//z为前len-1组总的数
		//y为第len组的第y-z-1个数,从0开始数
		//y为value的第pos个位置的数，pos也从0开始数
		int value = pow(10, len - 1) + (y-1 - z) / len;
		int pos = (y-1 - z) % len;
		
		int x = value / (int)pow(10, len-1 - pos) % 10;
		return x;
		
	}
	
	int Get2(int n){
		int x = 0;
		// do something
		//i 为第几行
		int i = 1, t = 1, len = 1, th = 10;
		int sum = 0;
		while (sum <= n){
			if (i >= th) {
				th *= 10;
				len++;
			}
			//
			if (len + sum >= n) {
				int k = len + sum - n;
				char s[20];
				sprintf(s, "%d", i);
				int slen = strlen(s);
				if (slen != len) {
					printf("ERROR\n");
				}
				x = s[slen - 1 - k] - '0';
				break;
			}
			sum += len;
			if (i == t) {
				len = 1;
				th = 10;
				i = 1;
				t++;
			}
			else {
				i++;
			}
		}
		return x;
	}
	
	void test()
	{
		int n;
		scanf("%d", &n);
		int r = Get1(n);
	
		printf("%d\n", r);

		int t = Get2(n);

		printf("%d\n", t);
	}
};

//int main(){
//	Cangku c;
//	c.test();
//	return 0;
//}