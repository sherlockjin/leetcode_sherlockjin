#include "common.h"
class Sort
{
public:
	//int test()
	//{
	//	//int origin[] = { 21,23,3,22,57,5 };
	//	int origin[] = { 5, 4, 3, 2, 1 };
	//	int s[10];
	//	int length = sizeof(origin) / sizeof(int);
	//	string type;
	//	cout << "请输入排序类型：";
	//	while (cin >> type)
	//	{
	//		if (type == "quickSort") {
	//			memcpy(s, origin, sizeof(origin));
	//			quickSort(s, 0, length - 1);
	//		}
	//		if (type == "bubbleSort") {
	//			memcpy(s, origin, sizeof(origin));
	//			bubbleSort(s, length);
	//		}
	//		if (type == "selectSort") {
	//			memcpy(s, origin, sizeof(origin));
	//			selectSort(s, length);
	//		}
	//		if (type == "heapSort") {
	//			memcpy(s, origin, sizeof(origin));
	//			heapSort(s, length);
	//		}
	//		if (type == "insertSort") {
	//			memcpy(s, origin, sizeof(origin));
	//			insertSort(s, length);
	//		}
	//		if (type == "mergeSort") {
	//			memcpy(s, origin, sizeof(origin));
	//			mergeSort(s, 0, length - 1);
	//		}
	//		for (int i = 0; i < length; i++)
	//		{
	//			cout << s[i] << ' ';
	//		}
	//		cout << endl;
	//		cout << "请输入排序类型：";

	//	}

	//	return 0;
	//}

	void bubbleSort(int s[], int length)
	{
		int flag = 0;
		for (int i = length - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (s[j] > s[j + 1]) {
					swap(s[j], s[j + 1]);
					flag = 1;
				}
			}
			if (flag == 0) {
				break;
			}
			flag = 0;
		}
	}

	void selectSort(int s[], int length) {

		for (int i = 0; i < length - 1; i++) {
			int minPos = i;
			for (int j = i + 1; j <= length - 1; j++) {
				if (s[j] < s[minPos]) {
					minPos = j;
				}
			}
			if (i != minPos) {
				swap(s[i], s[minPos]);
			}
		}
	}

	void insertSort(int s[], int length)
	{
		for (int i = 1; i < length; i++)
		{
			int temp = s[i];
			int j;
			for (j = i - 1; j >= 0; j--)
			{
				if (s[j] > temp)
				{
					s[j + 1] = s[j];
				}
				else {
					break;
				}
			}
			s[j + 1] = temp;
		}
	}

	void quickSort(int s[], int begin, int end)
	{
		if (begin < end) {
			int i = begin, j = end;
			int temp = s[i];
			while (i < j) {
				while (i < j && s[j] >= temp)
				{
					j--;
				}
				if (i < j)
				{
					s[i] = s[j];
					i++;
				}
				while (i < j && s[i] <= temp)
				{
					i++;
				}
				if (i < j)
				{
					s[j] = s[i];
					j--;
				}
			}
			s[i] = temp;
			quickSort(s, begin, i - 1);
			quickSort(s, i + 1, end);
		}
	}


	void heapSort(int s[], int length)
	{
		heapBuild(s, length);
		for (int i = length - 1; i >= 0; i--)
		{
			for (int i = 0; i < length; i++)
			{
				cout << s[i] << ' ';
			}
			cout << endl;
			swap(s[0], s[i]);
			heapAdjust(s, 0, i);
		}

	}
	void heapBuild(int s[], int length)
	{
		for (int i = (length - 2) / 2; i >= 0; i--)
		{
			heapAdjust(s, i, length);
		}
	}
	void heapAdjust(int s[], int posOfNode, int length)
	{
		int lchild = 2 * posOfNode + 1, rchild = 2 * posOfNode + 2;
		int posOfMax = posOfNode;
		if (posOfNode <= (length - 2) / 2)
		{
			if (lchild <= length - 1 && s[lchild] > s[posOfMax]) {
				posOfMax = lchild;
			}
			if (rchild <= length - 1 && s[rchild] > s[posOfMax]) {
				posOfMax = rchild;
			}
			if (posOfMax != posOfNode)
			{
				swap(s[posOfNode], s[posOfMax]);
				heapAdjust(s, posOfMax, length);
			}
		}
	}


	void mergeSort(int s[], int begin, int end)
	{
		if (begin < end) {
			int mid = (end + begin) / 2;
			mergeSort(s, begin, mid);
			mergeSort(s, mid + 1, end);
			merge(s, begin, mid, end);
		}
	}
	void merge(int s[], int begin, int mid, int end) {
		int* temp = (int *)malloc((end - begin + 1) * sizeof(int));
		int x = 0;
		int i = begin, j = mid + 1;

		while (i <= mid && j <= end)
		{
			if (s[i] < s[j])
			{
				temp[x++] = s[i++];
			}
			else {
				temp[x++] = s[j++];
			}
		}
		while (i <= mid) {
			temp[x++] = s[i++];
		}
		while (j <= end) {
			temp[x++] = s[j++];
		}
		memcpy(s + begin, temp, (end - begin + 1) * sizeof(int));
		free(temp);
	}

};
