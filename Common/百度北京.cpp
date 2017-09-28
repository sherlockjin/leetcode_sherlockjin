//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<iterator>
//#include<map>
//#include<vector>
//#include<stack>
//#include<queue>
//#include<string>
//using namespace std;
//
//int a[10005][8];
//int list[105][1005];
//
//// ������С�ѽڵ�
//struct MinHeapNode
//{
//	int element; // ������Ԫ��
//	int i; // ����������element�Ǵ��ĸ�����ȡ��
//	int j; // Ԫ����������һ��element������
//};
//
//// ����һ����С�ڵ�֮��ıȽϺ���
//void swap(MinHeapNode *x, MinHeapNode *y);
//
//class MinHeap
//{
//	MinHeapNode *harr; // ����һ��ָ�룬ָ����С�ѵĶѶ�Ԫ��
//	int heap_size; // �ѵĴ�С
//public:
//	// ���캯�������ѣ�������һ��ָ����С����С��
//	MinHeap(MinHeapNode a[], int size);
//
//	// �����ѣ��������������������ṹ
//	void MinHeapify(int);
//
//	// �����ڵ�����ӽڵ�
//	int left(int i) { return (2 * i + 1); }
//
//	// �����ڵ�����ӽڵ�
//	int right(int i) { return (2 * i + 2); }
//
//	// ��ȡ���ڵ�ֵ���Ѷ�Ԫ�أ�
//	MinHeapNode getMin() { return harr[0]; }
//
//	// �滻���ڵ㣨�Ѷ�Ԫ�أ������µ�����
//	void replaceMin(MinHeapNode x) { harr[0] = x;  MinHeapify(0); }
//};
//int mergeKArrays(int k,  int n)
//{
//	int *output = new int[n*k];  // �����������飬����������
//
//	// ����һ����СΪk����С�ѣ�����Ԫ��Ϊk�������е�ÿ������ĵ�һ��Ԫ��
//	MinHeapNode *harr = new MinHeapNode[k];
//	for (int i = 0; i < k; i++)
//	{
//		harr[i].element = list[i][0]; // ÿ������ĵ�һ��Ԫ�أ�ÿ���������СԪ�أ�
//		harr[i].i = i;  // ��ǰ��������
//		harr[i].j = 1;  // ��������һ��Ԫ�ص��������ж�Ԫ���Ƿ����꣩
//	}
//	MinHeap hp(harr, k); // ��������СΪk�����齨��
//
//	// ���ȡ���Ѷ�Ԫ�أ�������������У��������滻Ϊ�����������һԪ��
//	for (int count = 0; count < n*k; count++)
//	{
//		// ȡ�Ѷ�������
//		MinHeapNode root = hp.getMin();
//		output[count] = root.element;
//
//		// �滻�Ѷ�
//		if (root.j < n)
//		{
//			root.element = list[root.i][root.j];
//			root.j += 1;
//		}
//		// ��ǰ����Ԫ�������ˣ���Ѷ�Ϊ�����
//		else root.element = INT_MAX; //INT_MAX is for infinite
//
//		// �������Ԫ�أ����滻�Ѷ�Ԫ�أ������ѽṹ
//		hp.replaceMin(root);
//	}
//
//	return output[n];
//}
//
//MinHeap::MinHeap(MinHeapNode a[], int size)
//{
//	heap_size = size;
//	harr = a;  // store address of array
//	int i = (heap_size - 1) / 2;
//	while (i >= 0)
//	{
//		MinHeapify(i);
//		i--;
//	}
//}
//
//// �ݹ�ĵ���
//// This method assumes that the subtrees are already heapified
//void MinHeap::MinHeapify(int i)
//{
//	int l = left(i);
//	int r = right(i);
//	int smallest = i;
//	if (l < heap_size && harr[l].element < harr[i].element)
//		smallest = l;
//	if (r < heap_size && harr[r].element < harr[smallest].element)
//		smallest = r;
//	if (smallest != i)
//	{
//		swap(&harr[i], &harr[smallest]);
//		MinHeapify(smallest);
//	}
//}
//void swap(MinHeapNode *x, MinHeapNode *y)
//{
//	MinHeapNode temp = *x;  *x = *y;  *y = temp;
//}
//
//
//
//
//int f(int num[8], int n)
//{
//	int res = 0;
//	for (int i = 0; i < 8; i++)
//	{
//		res += (int)pow(n, i)*num[i];
//	}
//	return res;
//}
//int cal(int k, int n)
//{
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < k; j++)
//		{
//			list[j][i] = f(a[j], i);
//		}
//	}
//
//	int res = mergeKArrays(k, n);
//	return res;
//}
//
//
//
//
////int main()
////{
////	int k, n;
////	cin >> k;
////	for (int i = 0; i < k; i++)
////	{
////		for (int j = 0; j < 8; j++)
////		{
////			cin >> a[i][7-j];
////		}
////	}
////	cin >> n;
////	int res = cal(k,n);
////	cout << res << endl;
////	return 0;
////}