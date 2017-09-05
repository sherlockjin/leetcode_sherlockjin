#include"common.h"
class LargeNum{
public:
	string add(string s1, string s2){
		string res = "";
		int len1 = s1.length();
		int len2 = s2.length();
		int maxLen = len1 > len2 ? len1 : len2;
		int c = 0;
		int i, j;
		for (i = len1-1,j = len2 -1; i >= 0, j >= 0; i--,j--)
		{
			int temp = s1[i]-'0'+s2[j] - '0'+c;
			c = temp / 10;
			res += temp%10 + '0';
			
		}
		while (i >= 0){
			int temp = s1[i--] - '0' + c;
			c = temp / 10;
			res += temp % 10 + '0';
		}
		while (j >= 0){
			int temp = s2[j--] - '0' + c;
			c = temp / 10;
			res += temp % 10 + '0';
		}
		if (c == 1){
			res += '1';
		}
		return res;
	}
	void test(){

		string s1;
		string s2;
		while (1)
		{
			cin >> s1 >> s2;
			string res = add(s1, s2);
			for (int i = res.length() - 1; i >= 0; i--)
			{
				cout << res[i];
			}
		}
	}
};