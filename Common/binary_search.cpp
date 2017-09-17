#include"common.h"

class BinarySearch{
public:

	//二分查找，循环
	int binarySearchWithLoop(int *b, int first, int last, int w)
	{
		
		while (first <= last){
			int mid = first + (last - first) / 2;
			if (b[mid] == w){
				return mid;
			}
			else if (b[mid] < w){
				first = mid + 1;
			}
			else{
				last = mid - 1;
			}
		}
		return -1;
	}

	//二分查找，递归
	int binarySearch(int *b, int first, int last, int w)
	{

		if (first <= last){
			int mid = first + (last - first) / 2;
			if (b[mid] == w){
				return mid;
			}
			else if (b[mid] < w){
				return binarySearch(b, mid + 1, last, w);
			}
			else{
				return binarySearch(b, first, mid - 1, w);
			}
		}
		
		return -1;
	}

	//有多个相同的数
	void binarySearchWithDup(int *b, int first, int last, int w)
	{
		int mid;
		while (first <= last)
		{
			mid = first + (last - first) / 2;
			if (b[mid] > w)
				last = mid - 1;
			else if (b[mid] < w)
				first = mid + 1;
			else    //找到了该元素，则直接返回  
			{
				int l = lbs(b, first, mid - 1, w);
				if (l == -1){
					l = mid;
				}
				cout << "left:" << l << endl;
				int r = rbs(b, mid + 1, last, w);
				
				if (r == -1){
					r = mid;
				}
				cout << "right:" << r << endl;
				return;

			}
				
		}
		cout << "No the Num" << endl;//数组b中不存在该元素，则返回该元素应该插入的位置  
	}
	int lbs(int *b, int first, int last, int w)
	{
		int mid;
		while (first <= last)
		{
			mid = first + (last - first) / 2;
			if (b[mid] < w)
				first = mid + 1;
			else    //找到了该元素，则直接返回  
			{
				int l = lbs(b, first, mid - 1, w);
				if (l == -1){
					l = mid;
				}
				return l;
			}

		}
		return -1;//数组b中不存在该元素，则返回该元素应该插入的位置  
	}
	int rbs(int *b, int first, int last, int w)
	{
		int mid;
		while (first <= last)
		{
			mid = first + (last - first) / 2;
			if (b[mid] > w)
				last = mid - 1;
			else    //找到了该元素，则直接返回  
			{
				int r = rbs(b, mid+1, last, w);
				if (r == -1){
					r = mid;	
				}
				return r;
			}

		}
		return -1;//数组b中不存在该元素，则返回该元素应该插入的位置
	}
	void test(){
		int a[] = { 1, 2, 3, 4, 4, 4, 5 };
		binarySearchWithDup(a, 0, 6, 2);

	}

	//两个排序数组找第k小的数
	int find_kth(int A[], int m, int B[], int n, int k){
		if (m > n)
			return find_kth(B, n, A, m, k);
		if (m == 0)
			return B[k - 1];
		if (k == 1)
			return min(A[0], B[0]);

		int ia = min(k / 2, m);
		int ib = k - ia;
		if (A[ia - 1] < B[ib - 1]){
			return find_kth(A + ia, m - ia, B, n, k - ia);
		}
		else if (A[ia - 1] > B[ib - 1]){
			return find_kth(A, m, B + ib, n - ib, k - ib);
		}
		else{
			return A[ia - 1];
		}
	}

	void testFindKth(){
		int a[] = { 1, 2, 3, 4};
		int b[] = { 1, 2, 3, 4, 5 };
		int k;
		while (cin >> k){
			int res = find_kth(a, 4, b, 5, k);
			cout << res << endl;
		}
		
	}

};

//int main()
//{
//	BinarySearch bs;
//	bs.testFindKth();
//}