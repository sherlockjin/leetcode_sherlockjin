#include"common.h"
#define M 1010
class lcs{
	int LCS(char s1[], char s2[])
	{
		int len1 = strlen(s1), len2 = strlen(s2);

		//����c��¼ƥ�����,ģ���ά����
		char* c = (char*)malloc(sizeof(char)*len2);
		int len, i, j;
		len = 0;
		int* index = (int*)malloc(sizeof(char)*len2);
		int lengthOfIndex = 0;
		for (i = 0; i<len1; i++)
		{
			//�����������֮ǰ����Ԫ�س���ģ���Ϊ�����Ԫ����Ҫ����ǰ���Ԫ�ؼ���
			for (j = len2 - 1; j >= 0; j--)
			{
				if (s1[i] == s2[j])
				{
					if (i == 0 || j == 0)
						c[j] = 1;
					else
						c[j] = c[j - 1] + 1;
				}
				else
					c[j] = 0;

				if (c[j] > len)
				{
					len = c[j];
					lengthOfIndex = 0;
					index[lengthOfIndex++] = j;
				}
				if (c[j] == len)
				{
					index[lengthOfIndex++] = j;
				}

			}
		}
		for (j = 0; j < lengthOfIndex; j++){
			for (i = index[j] - len + 1; i <= index[j]; i++){
				cout << s2[i];
			}
			cout << endl;
		}
		/*for (i = 0; i < lengthOfIndex; i++){
		cout << index[i];
		}*/
		return len;
	}

	int LCSE(char s1[], char s2[])
	{
		int len1 = strlen(s1) + 1, len2 = strlen(s2) + 1;
		int** c = (int**)malloc(sizeof(int*)*(len1));
		for (int i = 0; i < len1; i++){
			c[i] = (int*)malloc(sizeof(int)*(len2));
		}
		for (int i = 0; i < len2; i++){
			c[0][i] = 0;
		}
		for (int i = 0; i < len1; i++){
			c[i][0] = 0;
		}
		for (int i = 1; i < len1; i++)
		{
			for (int j = 1; j < len2; j++)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					c[i][j] = c[i - 1][j - 1] + 1;
				}
				else if (c[i - 1][j] > c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
				}
				else{
					c[i][j] = c[i][j - 1];
				}
			}
		}
		return c[len1 - 1][len2 - 1];


	}

	int test()
	{
		char str1[M], str2[M];
		printf("�������ַ���query:");

		scanf("%s", str1);
		printf("�������ַ���text:");

		scanf("%s", str2);
		printf("���󳤶�Ϊ:");

		printf("%d\n", LCSE(str1, str2));
		return 0;

	}

};



