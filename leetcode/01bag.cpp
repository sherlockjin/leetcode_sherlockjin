#include"common.h"
class Bag{
public:
	int *out;
	void calFun(int m, int n){
		if (m < 1 || n < 1 || (n == 1 && m != 1)){
			return;
		}
		if (m < n){
			n = m;
		}

		if (m == n){
			out[n] = 1;
			for (int i = 1; i <= 4; i++){
				if (out[i]){
					cout << i << " ";
				}
			}
			cout << endl;
			out[n] = 0;
		}

		out[n] = 1;
		calFun(m - n, n - 1);

		out[n] = 0;
		calFun(m, n - 1);

	}

};
