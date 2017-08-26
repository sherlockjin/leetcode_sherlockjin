#include"common.h"

const int MAX_N = 1e5 + 5;


class SubMaxSum{

	int  a[MAX_N];
	int test() {

		int n = 0;//ÊäÈë¸öÊı
		while (~scanf("%d", &a[n]))
			n++;
		int res, last;
		res = -2147483647 - 1;
		last = 0;
		for (int i = 0; i < n; i++) {
			if (last > 0) {
				last += a[i];
			}
			else {
				last = a[i];
			}
			res = max(res, last);
		}
		printf("%d\n", res);
		return 0;

	}
};

