#include"common.h"

const int MAX_N = 1e5 + 5;

class MaxK{
	int n, a[MAX_N];
	int random_partion(int *p, int n)
	{
		int idx = rand() % n;
		swap(p[idx], p[n - 1]);
		int i = -1;    //i��ʾ���һ��С��p[n-1]��Ԫ�ص�λ��  
		int j = 0;     //j����ɨ������  
		for (j = 0; j<n; j++)
		{
			//��С��p[n-1]����������ǰ�벿��  
			if (p[j]<p[n - 1])
			{
				swap(p[++i], p[j]);
			}
		}
		swap(p[++i], p[n - 1]);
		return i;
	}

	int getMaxK(int *p, int n, int k)
	{
		int mid;
		if (k <= 0)
			return -1;
		if (n<k)
			return -1;
		//mid = random_partion(p, n);   //��ԭ�������һ�λ���  
		mid = random_partion(p, n,0,n-1);   //��ԭ�������һ�λ���
		if (mid == n - k)      //���mid==n-k����ô���ظ�ֵ������ǵ�k�����  
			return p[mid];
		else if (mid<n - k)
			return getMaxK(p + mid + 1, n - mid - 1, k);  //���mid<n-k����ô��k��������Ұ����飬������Ȼ�ǵ�k����  
		else
			return getMaxK(p, mid, k - (n - mid));   //���mid>n-k����ô��k�������������飬��������������ǵ�k-(n-mid)�����  
	}
	int random_partion(int *p, int n, int start, int end){
		int i = start, j = end;
		int index = rand() % n;
		int x = p[index];
		p[index] = p[end];
		while (i < j){
			while (i < j && p[i] <= x){
				i++;
			}
			if (i < j){
				p[j] = p[i];
				j--;
			}
			while (i < j && p[j] >= x){
				j--;
			}
			if (i < j){
				p[i] = p[j];
				i++;
			}
		}
		p[i] = x;
		return i;
	}
	int test()
	{
		int k;
		n = 0;
		while (~scanf("%d", &a[n]))
			n++;
		//scanf("%d", &k);
		k = a[n - 1];
		n--;
		int num = getMaxK(a, n, k);
		printf("%d\n", num);
		system("pause");
		return 0;
	}
};
