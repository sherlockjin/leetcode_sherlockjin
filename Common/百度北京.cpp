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
//// 定义最小堆节点
//struct MinHeapNode
//{
//	int element; // 带排序元素
//	int i; // 数组索引，element是从哪个数组取得
//	int j; // 元素索引，下一个element的索引
//};
//
//// 定义一个最小节点之间的比较函数
//void swap(MinHeapNode *x, MinHeapNode *y);
//
//class MinHeap
//{
//	MinHeapNode *harr; // 定义一个指针，指向最小堆的堆顶元素
//	int heap_size; // 堆的大小
//public:
//	// 构造函数（建堆）：构造一个指定大小的最小堆
//	MinHeap(MinHeapNode a[], int size);
//
//	// 调整堆：调整给定根结点的子树结构
//	void MinHeapify(int);
//
//	// 给定节点的左子节点
//	int left(int i) { return (2 * i + 1); }
//
//	// 给定节点的右子节点
//	int right(int i) { return (2 * i + 2); }
//
//	// 获取根节点值（堆顶元素）
//	MinHeapNode getMin() { return harr[0]; }
//
//	// 替换根节点（堆顶元素），重新调整堆
//	void replaceMin(MinHeapNode x) { harr[0] = x;  MinHeapify(0); }
//};
//int mergeKArrays(int k,  int n)
//{
//	int *output = new int[n*k];  // 最后输出的数组，保存排序结果
//
//	// 创建一个大小为k的最小堆，堆中元素为k个数组中的每个数组的第一个元素
//	MinHeapNode *harr = new MinHeapNode[k];
//	for (int i = 0; i < k; i++)
//	{
//		harr[i].element = list[i][0]; // 每个数组的第一个元素（每个数组的最小元素）
//		harr[i].i = i;  // 当前数组索引
//		harr[i].j = 1;  // 该数组下一个元素的索引（判断元素是否用完）
//	}
//	MinHeap hp(harr, k); // 对上述大小为k的数组建堆
//
//	// 逐次取出堆顶元素，存入输出数组中，并将其替换为所在数组的下一元素
//	for (int count = 0; count < n*k; count++)
//	{
//		// 取堆顶，存结果
//		MinHeapNode root = hp.getMin();
//		output[count] = root.element;
//
//		// 替换堆顶
//		if (root.j < n)
//		{
//			root.element = list[root.i][root.j];
//			root.j += 1;
//		}
//		// 当前数组元素用完了，设堆顶为无穷大
//		else root.element = INT_MAX; //INT_MAX is for infinite
//
//		// 如果还有元素，就替换堆顶元素，调整堆结构
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
//// 递归的调整
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