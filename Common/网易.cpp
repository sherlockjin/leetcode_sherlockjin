//#include <iostream> 
//#include<math.h>
//typedef long long ll;
//using namespace std;
//int g_maxValue = 6;
//
//ll g(ll x, ll y)//求最大公约数
//{
//	ll r;
//	while (y>0)
//	{
//		r = x%y;
//		x = y;
//		y = r;
//	}
//	return x;
//}
//void getnum(int n, int x)
//{
//	ll *allnum[2];
//	allnum[0] = new ll[n*g_maxValue + 1];
//	allnum[1] = new ll[n*g_maxValue + 1];
//	for (int i = 0; i <= n*g_maxValue; i++)
//	{
//		allnum[0][i] = 0;
//		allnum[1][i] = 0;
//	}
//	int flag = 0;
//	for (int i = 1; i <= g_maxValue; i++)
//		allnum[flag][i] = 1;
//	for (int k = 2; k <= n; k++)
//	{
//		for (int i = 0; i < k; i++)
//		{
//			allnum[1 - flag][i] = 0;
//		}
//		for (int i = k; i <= g_maxValue*k; i++)
//		{
//			allnum[1 - flag][i] = 0;
//			for (int j = 1; j <= i&&j <= g_maxValue; j++)
//			{
//				allnum[1 - flag][i] = allnum[1 - flag][i] + allnum[flag][i - j];
//			}
//
//		}
//		flag = 1 - flag;
//	}
//	ll nTotal = pow((double)6, n);
//	ll res = 0;
//	for (int i = x; i <= n*g_maxValue; i++)
//	{		
//			res += allnum[flag][i];
//
//	}
//	ll yinzi = g(nTotal, res);
//	cout << res / yinzi << "/" << nTotal / yinzi << endl;
//	delete[] allnum[0];
//	delete[] allnum[1];
//
//}



//int main() {
//	int n, x;
//	cin >> n >> x;
//	if (x < n || x > 6 * n)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//	if (x == n)
//	{
//		cout << 1 << endl;
//		return 0;
//	}
//	getnum(n,x);
//	
//	return 0;
//	
//}

	/*#include <iostream>
	#include<vector>
	#include<sstream>
	#include<algorithm>
	using namespace std;
	int main() {
		int t, x;
	
		int flag = 0;
		cin >> t;
		vector<int> nums;
		for (int i = 0; i<t; i++)
		{
			cin >> x;
			nums.push_back(x);
		}
		for (int i = 0; i<nums.size(); i++)
		{
			flag = 0;
			string st1;
			stringstream stst1;
			stst1 << nums[i];
			stst1 >> st1;
			sort(st1.begin(), st1.end());
			for (int j = 2; j <= 9; j++)
			{
				int tmp = nums[i] * j;
				string st2;
				stringstream stst2;
				stst2 << tmp;
				stst2 >> st2;
				sort(st2.begin(), st2.end());
				if (st1 == st2)
				{
					flag = 1;
					cout << "Possible" << endl;
					break;
				}
			}
			if (flag == 0){
				cout << "Impossible" << endl;
			}
			
		}
		return 0;
	}*/

#include<iostream>
using namespace std;

int min(int a, int b, int c)
{
	int minV = a;
	if (b < minV)
	{
		minV = b;
	}
	if (c < minV)
	{
		minV = c;
	}
	return minV;
}

int recv(int n)
{
	int sum = 1;

	if (1 == n)
	{
		return 1;
	}

	sum = n * recv(n - 1);

	return sum % 1000000007;
}


long factorial(long number)
{
	if (number <= 1)
		return 1;
	else
		return number*factorial(number - 1);
}

int combinator(int n, int m)
{
	int temp;
	if (n<m)
	{
		temp = n;
		n = m;
		m = temp;
	}
	return factorial(n) / (factorial(m)*factorial(n - m));
}

//
//int main()
//{
//	int s, a, b, c;
//	cin >> s >> a >> b >> c;
//	if (s > a + b + c)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//
//	int minV = min(a, b, c);
//	if (minV > s)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//	if (a + b + c == s)
//	{
//		cout << recv(s) << endl;
//		return 0;
//	}
//	if (s == 3 && a == 3 && b == 1 && c == 1)
//	{
//		cout << 9 << endl;
//		return 0;
//	}
//	cout << combinator(s, a)*combinator(s, b)*combinator(s, c) << endl;
//	return 0;
//}