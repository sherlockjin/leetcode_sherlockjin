#include"common.h"

class MidToPost{
public:

	int Is_OPTR(char x){//�ж��������������
		int temp;
		temp = 0;
		switch (x){
		case '^':
		case '*':
		case '/':
		case '+':
		case '-':
		case '(':
		case ')':
		case '#': temp = 1;
		}
		return(temp);
	}

	int Precede(char in, char out){
		int c_temp1, c_temp2;
		int temp;
		switch (in)	{
		case '^':c_temp1 = 5; break;
		case '*':
		case '/':c_temp1 = 4; break;
		case '+':
		case '-':c_temp1 = 2; break;
		case '(':c_temp1 = 0; break;
		case ')':c_temp1 = 7; break;
		case '#':c_temp1 = -1;
		}
		switch (out){
		case '^':c_temp2 = 6; break;
		case '*':
		case '/':c_temp2 = 3; break;
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
	int test(){
		int  t, n;
		int is_err, tempp, op;
		char w;
		string s;
		stack<char> optr;////��ʼ�������optrջ
		stack<int> opnd;////��ʼ��������opndջ
		scanf("%d\n", &n);
		optr.push('#');    //���Ƚ�#�������ջ
		for (t = 0; t < n; t++){
			w = getchar();
			while (w != '#' || optr.top() != '#'){
				if (!Is_OPTR(w))//w�������������1��w���������������0
				{
					s += w;// printf("%c", w);
					w = getchar();//ѭ��
				}
				else{
					switch (Precede(optr.top(), w))//���򣬱Ƚ�optr��ջ��ջ���������getchar()�����������������ȼ�
					{
					case -1://ջ��������ȼ��ߣ�������ջ
						optr.push(w);//��ջ����
						w = getchar();
						break;
					case 0://??? 
						optr.pop();
						w = getchar();
						break;
					case 1://ջ��������ȼ���
						op = optr.top();
						optr.pop();
						s += op;//printf("%c", op);
					}
				}
			}
			cout << s << endl;
			s = "";
			//if (t == n - 1)printf("\n");
		}
		
		return 0;
	}
};
//
//int main()
//{
//	MidToPost mtp;
//	mtp.test();
//	
//}