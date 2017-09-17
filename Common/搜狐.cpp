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


const int N = 1005;
int m[N][N];

class Souhu{

	/*

	类似
	http://www.bubuko.com/infodetail-110736.html
	添加最小的数字，使之成为回文
	8
	51 23 52 97 97 76 23 51
	*/
	int  calMin(int* str, int left, int right)
	{
		if (left == right)
		{
			return m[left][right] = 0;
		}
		else if (left + 1 == right)
		{
			if (str[left] == str[right])
			{
				return m[left][right] = 0;
			}
			else
			{
				return m[left][right] = min(str[left], str[right]);
			}
		}
		else
		{
			if (m[left][right] != -1)
			{
				return m[left][right];
			}
			else
			{
				if (str[left] == str[right])
				{
					return m[left][right] = calMin(str, left + 1, right - 1);
				}
				else
				{
					int a = calMin(str, left, right - 1) + str[right];
					int b = calMin(str, left + 1, right) + str[left];
					return m[left][right] = a < b ? a : b;
				}
			}
		}
	}
	int calMinHuiWen(){
		int str[N];
		int i, j, n;
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				m[i][j] = -1;
			}
		}
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
			sum += str[i];
		}

		cout << sum + calMin(str, 0, n - 1) << endl;
		return 0;
	}


	/*
	简化unix编码
	http://blog.csdn.net/wangyuquanliuli/article/details/46627819
	*/
	int simpath()
	{
		string path;
		cin >> path;
		stack<string> st;
		string current = "";
		path += "/";
		for (int i = 0; i < path.length(); i++)
		{
			if (path[i] == '/')
			{
				if (current == "..")
				{
					if (!st.empty())
						st.pop();
				}
				else if (current == ".")
				{
				}
				else if (current.length()>0)
				{
					st.push(current);
				}
				current = "";
			}
			else
			{
				current += path[i];
			}
		}
		string result = "";
		while (!st.empty())
		{
			result = "/" + st.top() + result;
			st.pop();
		}
		if (result.length() == 0)
			result = "/";
		cout << result << endl;
		
		return 0;
	}
};






