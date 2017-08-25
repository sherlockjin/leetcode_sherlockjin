#include"common.h"


class Sushu{
	
	int test(){
		int a[101];
		/*for (int i = 1; i < 101; i++){
			a[i] = 1; 
		}
		for (int i = 2; i < 101; i++){
			if (a[i] == 1){
				for (int j = i + i; j < 101; j += i){
					a[j] = 0;
				}
			}
		}
		for (int i = 1; i < 101; i++){
			if (a[i] == 1){
				cout << i << endl;
			}
		}*/
		int j, k;
		for (int i = 1; i < 101; i++){
			k = (int)sqrt(i);
			for (j = 2; j <= k; j++){
				if (i%j == 0){
					break;
				}
			}
			if (j>k){
				cout << i << endl;
			}
		}
		return 0;
	}
};
