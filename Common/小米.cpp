#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int LCSE(char s1[], char s2[])
{
	if (s1 == '\0' || s2 == '\0')
	{
		cout << -1 << " " << -1 << endl;
		return -1;
	}
		
	int text_len = strlen(s1);
	int find_len = strlen(s2);
	if (text_len < find_len)
	{
		cout << -1 << " " << -1 << endl;
		return -1;
	}
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
	if (c[len1 - 1][len2 - 1] != len2-1)
	{
		cout << -1 << " " << -1 << endl;
	}
	else{
		int end = -1;
		int begin = -1;
		for (int i = len1 - 1, j = len2 - 1; i >= 1 && j >= 1;)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				if (end == -1)
				{
					end = i - 1;
				}
				begin = i - 1;
				i--;
				j--;
			}
			else{
				if (c[i][j - 1] > c[i - 1][j])
				{
					j--;
				}
				else{
					i--;
				}
			}
		}
		cout << begin << " " << end << endl;
	}
	return c[len1 - 1][len2 - 1];


}


const int N = 111111;
long long  a[N];

//int main() {
//	int n;
//	while (cin >> n) {
//		a[0] = 1;
//		a[1] = 1;
//		for (int i = 2; i <= n; i++) {
//			a[i] = a[i - 1] + a[i - 2];
//		}
//		cout << a[n] << endl;
//	}
//	return 0;
//}

//int main()
//{
//	char buff[1000];
//	char pattern[1000];
//	while (gets(buff) != NULL)
//	{
//		int len = strlen(buff);
//		for (int j = len; j >= 0; j--){
//			if (buff[j] == ' '){
//				buff[j] = '\0';
//				for (int k = 0; k <= len - j; k++){
//					pattern[k] = buff[k + j + 1];
//				}
//				int lenPattern = strlen(pattern);
//				int value = LCSE(buff, pattern);
//				
//				//printf("%s\n%s\n",buff,pattern);
//				//printf("%d\n", kmp(buff, pattern));
//				//kmp(buff, pattern);
//
//				break;
//			}
//
//		}
//	}
//	return 0;
//}


#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
string multiply(string str1, string str2)
{
	int size1 = str1.size();
	int size2 = str2.size();
	string str(size1 + size2, '0');
	for (int i = size2 - 1; i >= 0; i--)
	{
		int multi = 0, add = 0;
		for (int j = size1 - 1; j >= 0; j--)
		{
			int temp1 = (str2[i] - '0')*(str1[j] - '0') + multi;
			multi = temp1 / 10;
			temp1 = temp1 % 10;
			int temp2 = str[i + j + 1] - '0' + temp1 + add;
			str[i + j + 1] = temp2 % 10 + 48;
			add = temp2 / 10;

		}
		str[i] += multi + add;
	}
	if (str[0] == '0')
	{
		str = str.substr(1, str.size());
	}
	return str;
}

string func(ll x)
{
	string str1, str2;
	string result = "1";
	for (ll i = 1; i <= x; i++)
	{
		result = multiply(result, to_string(i));
	}
	return result;
}

//int main()
//{
//	ll n;
//	cin >> n;
//	cout << func(n) << endl;
//}
