#include"common.h"

void eightqueen(int i);
const int sizew = 4;
char queen[sizew][sizew];//�������
bool a[sizew], b[sizew + sizew - 1], c[sizew + sizew - 1];//aΪ�г�ͻ��bΪ�������߳�ͻ�����Ͻ�Ϊ0��Ϊi-j+(sizew-1)����cΪ�Ӷ����ߣ����Ͻ�Ϊ0,��i+j)��
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
		if (!a[j] && !b[i - j + sizew-1] && !c[i + j]){//û�г�ͻ
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
				�ָ��ֳ���������һ���ʺ��Ƿ�˳�����ã���Ӧ�ûָ�
				�����һ���ʺ����ʧ�ܣ���ô��Ȼ�����η��õĻʺ�ȥ�������·��ã�
				�����һ���ʺ���óɹ�����ζ�ű��η����Ѿ�������������һ���ӣ���ʱ��Ҫ�ָ��ֳ���������һ�����·���
			*/
			queen[i][j] = '*';
			a[j] = false;
			b[i - j + sizew-1] = false;
			c[i + j] = false;
			
		}
		
	}
}