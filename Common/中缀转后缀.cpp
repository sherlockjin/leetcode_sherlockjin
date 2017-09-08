#include"common.h"

class MidToPost{
public:

	int Is_OPTR(char x){//判断运算符和运算数
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
		if (c_temp1<c_temp2) temp = -1;//栈外算符优先级高，入栈
		if (c_temp1 == c_temp2) temp = 0;
		if (c_temp1>c_temp2) temp = 1;//栈内算符优先级高，运算
		return(temp);
	}
	int test(){
		int  t, n;
		int is_err, tempp, op;
		char w;
		string s;
		stack<char> optr;////初始化运算符optr栈
		stack<int> opnd;////初始化运算数opnd栈
		scanf("%d\n", &n);
		optr.push('#');    //首先将#进运算符栈
		for (t = 0; t < n; t++){
			w = getchar();
			while (w != '#' || optr.top() != '#'){
				if (!Is_OPTR(w))//w是运算符，返回1，w不是运算符，返回0
				{
					s += w;// printf("%c", w);
					w = getchar();//循环
				}
				else{
					switch (Precede(optr.top(), w))//否则，比较optr堆栈中栈顶的算符与getchar()函数读入的算符的优先级
					{
					case -1://栈外算符优先级高，继续入栈
						optr.push(w);//入栈操作
						w = getchar();
						break;
					case 0://??? 
						optr.pop();
						w = getchar();
						break;
					case 1://栈内算符优先级高
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