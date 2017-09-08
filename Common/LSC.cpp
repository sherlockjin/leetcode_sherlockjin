#include"common.h"
#define M 1010
class lcs{
public:

	
	int LCS2(char s1[], char s2[])
	{
		int len1 = strlen(s1);
		const int len2 = strlen(s2);
		//int dp[2][100] = {0};
		int** dp = (int**)malloc(sizeof(int*)*(2));
		for (int i = 0; i < 2; i++){
			dp[i] = (int*)malloc(sizeof(int)*(len2+1));
			memset(dp[i], 0, sizeof(dp[i]));
		}
		int rowFlag = 1;
		for (int i = 1; i <= len1; ++i) {

			for (int j = 1; j <= len2; ++j) {

				if (s1[i - 1] == s2[j - 1])
					//dp[i][j]=dp[i-1][j-1]+1;
					dp[rowFlag][j] = dp[!rowFlag][j - 1] + 1;
				else
					dp[rowFlag][j] = max(dp[!rowFlag][j], dp[rowFlag][j - 1]);
			}
			rowFlag = !rowFlag;
		}
		return dp[!rowFlag][len2];

	}
	int LCS(char s1[], char s2[])
	{
		int len1 = strlen(s1), len2 = strlen(s2);

		//����c��¼ƥ�����,ģ���ά����
		char* c = (char*)malloc(sizeof(char)*len2);
		memset(c, 0, sizeof(c));
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
			
				if (c[j] > len)
				{
					len = c[j];
					//lengthOfIndex = 0;
					//index[lengthOfIndex++] = j;
				}
				/*else if (c[j] == len)
				{
					index[lengthOfIndex++] = j;
				}*/

			}
		}
		/*for (j = 0; j < lengthOfIndex; j++){
			for (i = index[j] - len + 1; i <= index[j]; i++){
				cout << s2[i];
			}
			cout << endl;
		}*/
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
	int lcsNlogN(char* s1, char* s2){
		map<char, vector<int>> myMap;
		int len1 = strlen(s1), len2 = strlen(s2);
		for (int i = 0; i < len2; i++){
			myMap[s2[i]].push_back(i);
		}
		vector<int> res;
		for (int i = 0; i < len1; i++){
			if (!myMap[s1[i]].empty()){
				for (int j = myMap[s1[i]].size() - 1; j >= 0; j--){
					res.push_back(myMap[s1[i]][j]);
				}
			}
		}
		return LIS(res, res.size());
	}
	//�޸ĵĶ��ֲ����㷨����������Ԫ����Ҫ�����λ�á�  
	int BiSearch(vector<int> &b, int len, int w)
	{
		int left = 0, right = len - 1;
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (b[mid] > w)
				right = mid - 1;
			else if (b[mid] < w)
				left = mid + 1;
			else    //�ҵ��˸�Ԫ�أ���ֱ�ӷ���  
				return mid;
		}
		return left;//����b�в����ڸ�Ԫ�أ��򷵻ظ�Ԫ��Ӧ�ò����λ��  
	}
	int LIS(vector<int> &array, int n)
	{
		int len = 1;
		vector<int> B;
		B.push_back(array[0]);
		int i, pos = 0;

		for (i = 1; i<n; ++i)
		{
			if (array[i] > B[len - 1]) //�������B������Ԫ�أ���ֱ�Ӳ��뵽B����ĩβ  
			{
				B.push_back(array[i]);
				++len;
			}
			else
			{
				pos = BiSearch(B, len, array[i]); //���ֲ�����Ҫ�����λ��  
				B[pos] = array[i];
			}
		}

		return len;
	}
	int test()
	{
		char str1[M], str2[M];
		printf("�������ַ���query:");

		scanf("%s", str1);
		printf("�������ַ���text:");

		scanf("%s", str2);
		printf("���󳤶�Ϊ:");

		printf("%d\n", LCS2(str1, str2));
		return 0;

	}

};



