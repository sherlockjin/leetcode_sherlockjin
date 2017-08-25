#include"common.h"

const int size = 4;


class Queen{
	char queen[size][size];//存放棋盘

	bool a[size];
	bool b[size + size - 1];
	bool c[size + size - 1];//a为列冲突，b为主对象线冲突（右上角为0，为i-j+(size-1)），c为从对象线（左上角为0,（i+j)）
	
	int queenNum = 0;

	void eightqueen(int i){

		if (i >= size){
			return;
		}
		for (int j = 0; j < size; j++){
			if (!a[j] && !b[i - j + size - 1] && !c[i + j]){//没有冲突
				queen[i][j] = '@';
				a[j] = true;
				b[i - j + size - 1] = true;
				c[i + j] = true;
				if (i < size - 1){
					eightqueen(i + 1);
				}
				else{
					queenNum++;
					for (int i = 0; i < size; i++){
						for (int j = 0; j < size; j++){
							cout << queen[i][j] << " ";
						}
						cout << endl;
					}
					cout << endl << endl;
				}

				/*
				恢复现场，无论下一个皇后是否顺利放置，都应该恢复
				如果下一个皇后放置失败，那么自然将本次放置的皇后去除，重新放置；
				如果下一个皇后放置成功，意味着本次放置已经满足条件，是一个接，此时需要恢复现场，进行下一次重新放置
				*/
				queen[i][j] = '*';
				a[j] = false;
				b[i - j + size - 1] = false;
				c[i + j] = false;

			}

		}
	}
	int test(){
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				queen[i][j] = '*';
			}
		}
		for (int i = 0; i < size; i++){
			a[i] = false;
		}
		for (int i = 0; i < size + size - 1; i++){
			b[i] = false;
			c[i] = false;
		}
		eightqueen(0);
		cout << queenNum << endl;
		return 0;
	}
};


