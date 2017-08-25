#include"common.h"

const int size = 4;


class Queen{
	char queen[size][size];//�������

	bool a[size];
	bool b[size + size - 1];
	bool c[size + size - 1];//aΪ�г�ͻ��bΪ�������߳�ͻ�����Ͻ�Ϊ0��Ϊi-j+(size-1)����cΪ�Ӷ����ߣ����Ͻ�Ϊ0,��i+j)��
	
	int queenNum = 0;

	void eightqueen(int i){

		if (i >= size){
			return;
		}
		for (int j = 0; j < size; j++){
			if (!a[j] && !b[i - j + size - 1] && !c[i + j]){//û�г�ͻ
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
				�ָ��ֳ���������һ���ʺ��Ƿ�˳�����ã���Ӧ�ûָ�
				�����һ���ʺ����ʧ�ܣ���ô��Ȼ�����η��õĻʺ�ȥ�������·��ã�
				�����һ���ʺ���óɹ�����ζ�ű��η����Ѿ�������������һ���ӣ���ʱ��Ҫ�ָ��ֳ���������һ�����·���
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


