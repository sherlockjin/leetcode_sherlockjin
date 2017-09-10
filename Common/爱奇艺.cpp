#include"common.h"
using namespace std;

class Aiqiyi{
	//sqrt(a*b)是整数的个数，其中1<=a<=m，1<=b<=n
	int baoli()
	{
		int m, n;
		cin >> n >> m;
		int res = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				int x = i*j;
				if (x == (int)sqrt(x)*(int)sqrt(x)){
					res++;
				}
			}
		}
		cout << res << endl;
		return 0;
	}
	int hash()
	{
		int m, n;
		int x[100005];
		cin >> n >> m;
		int max = n > m ? n : m;
		int min = n <= m ? n : m;
		int res = 0;
		int temp = 0;
		for (int i = 1; i <= max; i++){
			if (i == (long long)sqrt(i)*(long long)sqrt(i)){
				temp++;
			}
			x[i] = temp;
		}
		for (int i = 1; i <= min; i++){
			if (i == (long long)sqrt(i)*(long long)sqrt(i)){
				res += x[max];
			}
			else{
				res += x[max / i];
			}
		}
		cout << res << endl;
		return 0;
	}
	//奶牛编号
	int fenpei()
	{
		int n;
		int x[55];

		int res = 1;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> x[i];
		}
		sort(x, x + n);
		for (int i = 0; i < n; i++){
			res = res*(x[i] - (i + 1) + 1);
		}
		cout << res << endl;
		return 0;

	}

	int lcs(const char s1[], const char s2[])
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
	//aabaab是平方串
	int pingfangchuan()
	{
		string s;
		cin >> s;
		int lcsLength = 0;
		int res = 0;
		for (int i = 1; i < s.length(); i++)
		{
			string s1 = s.substr(0, i);
			string s2 = s.substr(i);
			lcsLength = lcs(s1.c_str(), s2.c_str());
			if (lcsLength > res){
				res = lcsLength;
			}
		}
		cout << res * 2 << endl;
		return 0;

	}
	//括号匹配
	int match(){
		string s;
		stack<char> st;
		int dep = 0;
		int maxDep = 0;
		cin >> s;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '('){
				st.push(s[i]);
				dep++;
				if (dep>maxDep){
					maxDep = dep;
				}
			}
			else if (s[i] == ')'){
				dep--;
				st.pop();
			}
		}
		cout << maxDep << endl;

		return 0;
	}
};
