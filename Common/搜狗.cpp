#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;

typedef long long LL;

const int N = 2 * 300000 + 5;
double a[N];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%lf", &a[i]);
//	}
//	
//	int m = n;
//	for (int i = 0; i < n; ++i) 
//	{
//		if (a[i] < 180)
//		{
//			a[m++] = a[i] + 360;
//		}
//	}
//	int j = 0;
//	LL ans = 0;
//	for (int i = 0; i < n; i++) 
//	{
//		while (j < m && (a[j] - a[i] < 180))
//		{
//			j++;
//		}
//		LL k = j - 1 - i;
//		ans += k*(k - 1) / 2;
//	}
//	printf("%lld\n", ans);
//
//	return 0;
//}