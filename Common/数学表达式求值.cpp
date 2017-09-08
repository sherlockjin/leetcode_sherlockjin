#include"common.h"

class CalValue{
public:
	//�ж��ַ�x�Ƿ��ǲ�����
	int Is_OPTR(char x){//�ж��������������
		int temp;
		temp = 0;
		switch (x){
		case '^':
		case '*':
		case '/':
		case '%':
		case '+':
		case '-':
		case '(':
		case ')':
		case '#': temp = 1;
		}
		return(temp);
	}

	//�Ƚ�ջ��Ԫ��in�͵�ǰ������out�����ȼ�
	int Precede(char in, char out){
		int c_temp1, c_temp2;
		int temp;
		switch (in)	{
		case '^':c_temp1 = 5; break;
		case '*':
		case '/':
		case '%':c_temp1 = 4; break;
		case '+':
		case '-':c_temp1 = 2; break;
		case '(':c_temp1 = 0; break;
		case ')':c_temp1 = 7; break;
		case '#':c_temp1 = -1;
		}
		switch (out){
		case '^':c_temp2 = 6; break;
		case '*':
		case '/':
		case '%':c_temp2 = 3; break;
		case '+':
		case '-':c_temp2 = 1; break;
		case '(':c_temp2 = 7; break;
		case ')':c_temp2 = 0; break;
		case '#':c_temp2 = -1;
		}
		if (c_temp1<c_temp2) temp = -1;//ջ��������ȼ��ߣ���ջ
		if (c_temp1 == c_temp2) temp = 0;
		if (c_temp1>c_temp2) temp = 1;//ջ��������ȼ��ߣ�����
		return(temp);
	}

	//����a op b
	int Execute(int a, char op, int b){
		int s;
		switch (op){
		case '^':s = (int)pow((double)a, b); break;
		case '*':s = a*b; break;
		case '/':s = a / b; break;
		case '%':s = a%b; break;
		case '+':s = a + b; break;
		case '-':s = a - b; break;
		}
		return(s);
	}

	bool isNegative(char* expression, int i)
	{
		if (i == 0 && expression[i] == '-')
		{
			return true;// �Ǹ���
		}
		if (i >= 1 && expression[i] == '-' &&
			(expression[i - 1] == '+' || expression[i - 1] == '-' || expression[i - 1] == '*' || expression[i - 1] == '/' || expression[i - 1] == '%' || expression[i - 1] == '(')
			)
		{
			return true;//�Ǹ���
		}
		return false;
	}

	int caculate(char expression[]){
		int len, i, j = 0;
		int o;//+-1����������
		char t[10];
		stack<char> optr;////��ʼ�������optrջ
		stack<int> opnd;////��ʼ��������opndջ
		
		int op, temp;
		int firOpnd,secOpnd;

		optr.push('#');    //���Ƚ�#�������ջ
		len = strlen(expression);
		expression[len] = '#';
		expression[len + 1] = '\0';
		len = len + 1;
		
		for (i = 0; i < len; ){
			if (Is_OPTR(expression[i]) && !isNegative(expression,i)){

				switch (Precede(optr.top(), expression[i]))//���򣬱Ƚ�optr��ջ��ջ���������getchar()�����������������ȼ�
				{
				case -1://ջ��������ȼ��ߣ�������ջ
					optr.push(expression[i]);//��ջ����
					i++;
					break;
				case 0://???  
					optr.pop();
					i++;
					break;
				case 1://ջ��������ȼ���
					secOpnd = opnd.top();
					opnd.pop();
					firOpnd = opnd.top();
					opnd.pop();
					op = optr.top();
					optr.pop();
					opnd.push(Execute(firOpnd, op, secOpnd));
				}					
				
			}
			else{
				o = 1;
				if (expression[i] == '-'){
					o = -1;
					i++;
				}
				j = 0;
				while (expression[i] >= '0' && expression[i] <= '9'){
					t[j++] = expression[i++];
				}
				t[j] = '\0';
				int num = o*atoi(t);
				opnd.push(num);
			}

		}
		return opnd.top();
	}
};


//int main(){
//	CalValue calValue;
//	char expression[100];
//	//string s1,s2;
//	//cin >> s1 >> s2;
//	//int i = stoi(s1); �ȼ��� atoi(s.c_str())
//	//int j = stoi(s2);
//	//cout << i+j << endl;
//	while (gets(expression) != NULL){
//		if (strcmp(expression, "end") == 0){
//			return 0;
//		}
//		int value = calValue.caculate(expression);
//		cout << "result = " << value << endl;
//	}
//	return 0;
//}