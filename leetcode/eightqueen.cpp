#include"common.h"

void eightqueen(int i);
const int sizew = 4;
char queen[sizew][sizew];//存放棋盘
bool a[sizew], b[sizew + sizew - 1], c[sizew + sizew - 1];//a为列冲突，b为主对象线冲突（右上角为0，为i-j+(sizew-1)），c为从对象线（左上角为0,（i+j)）
int queenNum = 0;

//int main(){
//	for (int i = 0; i < sizew; i++){
//		for (int j = 0; j < sizew; j++){
//			queen[i][j] = '*';
//		}
//	}
//	for (int i = 0; i < sizew; i++){
//		a[i] = false;
//	}
//	for (int i = 0; i < sizew + sizew - 1; i++){
//		b[i] = false;
//		c[i] = false;
//	}
//	eightqueen(0);
//	cout << queenNum << endl;
//	return 0;
//}

void eightqueen(int i){

	if (i >= sizew){
		return;
	}
	for (int j = 0; j < sizew; j++){
		if (!a[j] && !b[i - j + sizew-1] && !c[i + j]){//没有冲突
			queen[i][j] = '@';
			a[j] = true;
			b[i - j + sizew-1] = true;
			c[i + j] = true;
			if (i < sizew - 1){
				eightqueen(i + 1);
			}
			else{
				queenNum++;
				for (int i = 0; i < sizew; i++){
					for (int j = 0; j < sizew; j++){
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
			b[i - j + sizew-1] = false;
			c[i + j] = false;
			
		}
		
	}
}