#include"common.h"

const int MAX_N = 1e5 + 5;


class SubMaxSum{
public:
	int  a[MAX_N];
	int test() {

		int n = 0;//ÊäÈë¸öÊı
		while (~scanf("%d", &a[n]))
			n++;
		int res, last;
		res = -2147483647 - 1;
		last = 0;
		int begin = 0, end = 0,gbegin = 0, gend = 0;
		for (int i = 0; i < n; i++) {
			if (last > 0) {
				last += a[i];
			}
			else {
				begin = i;
				last = a[i];
			}
			end = i;
			if (last > res){
				gbegin = begin;
				gend = end;
				res = last;
			}
			
		}
		printf("%d\n", res);
		return 0;

	}
};

//int main()
//{
//	SubMaxSum sms;
//	sms.test();
//}

