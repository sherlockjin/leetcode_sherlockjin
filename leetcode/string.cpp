#include"common.h"

class SolutionString {
public:
	bool match(char a, char b);
	bool isValid(string s);

	int longestValidParentheses(string s);

	void testIsValid();

	void testLongestValidParentheses();
};
bool SolutionString::match(char a, char b)
{
	if (a == '(' && b == ')')
	{
		return true;
	}
	else if (a == '[' && b == ']') {
		return true;
	}
	else if (a == '{' && b == '}') {
		return true;
	}
	return false;
}

bool SolutionString::isValid(string s) {
	

	if (s.length() == 0) {
		return true;
	}
	stack<char> tmpStack;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			tmpStack.push(s[i]);
		}
		else{
			if (tmpStack.empty()) {
				return false;
			}
			else {
				char top = tmpStack.top();
				if (!match(top, s[i])) {
					return false;
				}
				else {
					tmpStack.pop();
				}
			}
		}
	}
	
	return tmpStack.empty();
	
}


//int SolutionString::longestValidParentheses(string s) {
//	if (s.length() == 0) {
//		return 0;
//	}
//	stack<int> tmpStack;
//	int maxLength = 0;
//	int bottom = -1;
//	for (int i = 0; i < s.length(); i++) {
//		if (s[i] == '(') {
//			tmpStack.push(i);
//		}
//		else {
//			if (tmpStack.empty())//δƥ��
//			{
//				bottom = i;
//			}
//			else {			//ƥ��
//				tmpStack.pop();
//				if (tmpStack.empty()) {
//					maxLength = max(maxLength, i - bottom);
//				}
//				else {
//					maxLength = max(maxLength, i - tmpStack.top());
//				}
//			}
//		}
//	}
//	return maxLength;
//}
//())))(()()
int SolutionString::longestValidParentheses(string s) {
	if (s.length() == 0) {
		return 0;
	}
	stack<int> tmpStack;
	stack<char> tmpCharStack;
	int maxLength = 0;
	int bottom = -1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			tmpStack.push(i);
			tmpCharStack.push(s[i]);
		}
		else {
			if (tmpStack.empty()||!match(tmpCharStack.top(),s[i]))//δƥ��
			{
				bottom = i;
				while (!tmpStack.empty()) {
					tmpStack.pop();
					tmpCharStack.pop();
				}
			}
			else {			//ƥ��
				tmpStack.pop();
				tmpCharStack.pop();
				if (tmpStack.empty()) {
					maxLength = max(maxLength, i - bottom);
				}
				else {
					maxLength = max(maxLength, i - tmpStack.top());
				}
			}
		}
	}
	return maxLength;
}

void SolutionString::testIsValid() {
	string s = "(()(())";
	if (isValid(s)) {
		cout << "�Ϸ�" << endl;
	}
	else {
		cout << "���Ϸ�" << endl;
	}
}
void SolutionString::testLongestValidParentheses() {
	string s = ")}((]))";
	int length = longestValidParentheses(s);
	cout << "���ƥ�䳤��Ϊ" << length << endl;
}