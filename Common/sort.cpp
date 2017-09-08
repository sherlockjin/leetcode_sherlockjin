#include "common.h"
class Sort
{
public:
	void test()
	{
		int origin[] = { 21,23,3,22,57,5 };
		//int origin[] = { 5, 4, 3, 2, 1 };
		int s[10];
		int length = sizeof(origin) / sizeof(int);
		string type;
		cout << "请输入排序类型：";
		while (cin >> type)
		{
			if (type == "quickSort") {
				memcpy(s, origin, sizeof(origin));
				quickSortBest(s, 0, length - 1);
			}
			if (type == "bubbleSort") {
				memcpy(s, origin, sizeof(origin));
				bubbleSort(s, length);
			}
			if (type == "selectSort") {
				memcpy(s, origin, sizeof(origin));
				selectSort(s, length);
			}
			if (type == "heapSort") {
				memcpy(s, origin, sizeof(origin));
				heapSort(s, length);
			}
			if (type == "insertSort") {
				memcpy(s, origin, sizeof(origin));
				insertSort(s, length);
			}
			if (type == "mergeSort") {
				memcpy(s, origin, sizeof(origin));
				mergeSort(s, 0, length - 1);
			}
			for (int i = 0; i < length; i++)
			{
				cout << s[i] << ' ';
			}
			cout << endl;
			cout << "请输入排序类型：";

		}
	}

	//交换类排序  冒泡是稳定的，快速排序 不稳定的
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

	void quickSort(int s[], int begin, int end)
	{
		if (begin < end) {
			int i = begin, j = end;
			int index = rand() / (end - begin + 1);
			int temp = s[index];
			s[index] = s[i];
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

	//选择类排序 都是不稳定的， 简单选择排序和堆排序都不稳定
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

	//插入类排序是稳定的，插入排序和希尔排序
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



	//最好的快速排序
	void insertSort(int s[], int begin, int end)
	{
		for (int i = begin+1; i <= end; i++)
		{
			int temp = s[i];
			int j;
			for (j = i - 1; j >= begin; j--)
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
	void quickSortBest(int s[], int begin, int end)
	{
		if (begin >= end){
			return;
		}
		if (end - begin + 1 < 10){
			insertSort(s, begin,end);
		}
		else{
			int index = partition(s, begin, end);
			if (index > begin){
				quickSortBest(s, begin, index - 1);
			}
			if (index < end){
				quickSortBest(s, index + 1, end);
			}
		}
		//以下是使用尾递归优化
		/*else{
			while (begin < end) {
				int index = partition(s, begin, end);
				if (index > begin){
					quickSortBest(s, begin, index - 1);
				}
				begin = begin + 1;
			}
		}*/
	}
	int partition(int s[], int begin, int end){
		if (begin >= end){
			return begin;
		}
		int index = rand() / (end - begin + 1) + begin;
		swap(s[begin], s[end]);
		int small = begin - 1;
		for (index = begin; index < end; index++){
			if (s[index] < s[end]){
				small++;
				if (small != index){
					swap(s[small], s[index]);
				}
			}
		}
		small++;
		swap(s[small], s[end]);
		return small;
	}


	//堆排序
	void heapSort(int s[], int length)
	{
		heapBuild(s, length);
		for (int i = length - 1; i >= 0; i--)
		{
			for (int j = 0; j < length; j++)
			{
				cout << s[j] << ' ';
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

	//归并排序 是稳定的
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
//int main(){
//	Sort s;
//	s.test();
//	return 0;
//}
