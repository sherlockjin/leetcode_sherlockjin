#include "common.h"
class StrMATCH
{
public:
	char buff[50000 + 5];
	char pattern[50000 + 5];
	int bf(char *text, char *find)
	{
		if (text == '\0' || find == '\0')
			return -1;
		int find_len = strlen(find);
		int text_len = strlen(text);
		if (text_len < find_len)
			return -1;
		char *s = text;
		char *p = s;
		char *q = find;
		while (*p != '\0')
		{
			if (*p == *q)
			{
				p++;
				q++;
			}
			else
			{
				s++;
				p = s;
				q = find;
			}
			if (*q == '\0')
			{
				return (p - text) - (q - find);
			}
		}
		return -1;
	}

	//KMPËã·¨
	void getNext(char *pattern, int* next){
		int k = -1;
		int j = 0;
		next[j] = k;

		while (j < strlen(pattern)){
			if (k == -1 || pattern[j] == pattern[k]){
				j++;
				k++;
				next[j] = k;
			}
			else{
				k = next[k];
			}
		}
	}

	void getNext2(char *pattern, int* next){
		int k = 0;
		int j = 1;
		next[0] = 0;
		int errorcount = 0;
		while (j < strlen(pattern)){
			if (pattern[j] == pattern[k]){
				k++;
				next[j] = k;
				j++;
			}
			else{
				errorcount++;
				if (errorcount < 2){
					k++;
					j++;
					next[j] = k;
				}
				else{
					if (k != 0){
						k = next[k - 1];
					}
					else{
						next[j] = 0;
						j++;
					}
					errorcount = 0;
				}
			}
		}
		for (int i = 0; i < strlen(pattern); i++){
			printf("%d ", next[i]);
		}
		printf("\n");
	}
	void kmp2(char *text, char *pattern)
	{
		if (text == '\0' || pattern == '\0')
			printf("%d\n", -1);
		int pattern_len = strlen(pattern);
		int text_len = strlen(text);
		if (text_len < pattern_len)
			printf("%d\n", -1);
		int *next = (int *)malloc(sizeof(int)*pattern_len);
		memset(next, 0, pattern_len*sizeof(int));
		//initial the kmp base array: map  
		getNext2(pattern, next);
		int flag = 0;
		int errorcount = 0;
		int pos_i = 0, pos_j = 0;
		for (int i = 0, j = 0; i<text_len && j < pattern_len;)
		{
			/*if ( (text[i] == pattern[j]))
			{
			i++;
			j++;
			}
			else
			{
			j = next[j];

			}
			if (j == (pattern_len)){
			printf("%d\n", i - j);
			flag = 1;
			j = 0;
			i = i - j + 1;
			}*/
			if (text[i] == pattern[j])
			{
				i++;
				j++;
			}
			else
			{
				if (errorcount == 0){
					pos_i = i;
					pos_j = j;
					i++;
					j++;
					errorcount++;
				}
				else
				{
					if (pos_j - 1 >= 0){
						j = next[pos_j - 1];
						i = pos_i;
					}
					else{
						j = 0;
						i = pos_i + 1;
					}

					errorcount = 0;
				}
			}

			if (j == (pattern_len)){
				printf("%d\n", i - j);
				errorcount = 0;
				flag = 1;
				i = i - j + 1;
				j = 0;

			}

		}
		//free(next);
		if (flag == 0){
			printf("%d\n", -1);
		}

	}

	void kmp(char *text, char *pattern)
	{
		if (text == '\0' || pattern == '\0')
			printf("%d\n", -1);
		int pattern_len = strlen(pattern);
		int text_len = strlen(text);
		if (text_len < pattern_len)
			printf("%d\n", -1);
		int *next = (int *)malloc(sizeof(int)*pattern_len);
		memset(next, 0, pattern_len*sizeof(int));
		//initial the kmp base array: map  
		getNext(pattern, next);
		int flag = 0;
		for (int i = 0, j = 0; i<text_len && j < pattern_len;)
		{

			if ((j == -1) || (text[i] == pattern[j]))
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];

			}
			if (j == (pattern_len)){
				printf("%d\n", i - j);
				flag = 1;
				j = 0;
				i = i - j + 1;
			}

		}
		free(next);
		if (flag == 0){
			printf("%d\n", -1);
		}

	}

	//int main(){
	//	int t;
	//	scanf("%d\n", &t);
	//	for (int i = 0; i < t; i++){
	//		gets(buff);
	//		int len = strlen(buff);
	//		for (int j = len; j >= 0; j--){
	//			if (buff[j] == ' '){
	//				buff[j] = '\0';
	//				for (int k = 0; k <= len - j; k++){
	//					pattern[k] = buff[k + j + 1];
	//				}
	//				// value = bf(buff, pattern);
	//				//printf("%s\n%s\n",buff,pattern);
	//				//printf("%d\n", kmp(buff, pattern));
	//				kmp2(buff, pattern);
	//				
	//				break;
	//			}
	//			
	//		}
	//		//printf("%s\n", buff);
	//	}
	//	return 0;
	//}

};
