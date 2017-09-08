//#include"common.h"
//
//class BinarySearch{
//public:
//	int binarySearch(int *b, int first, int last, int w)
//	{
//		
//		while (first <= last){
//			int mid = first + (last - first) / 2;
//			if (b[mid] == w){
//				return mid;
//			}
//			else if (b[mid] < w){
//				first = mid + 1;
//			}
//			else{
//				last = mid - 1;
//			}
//		}
//		return -1;
//	}
//	int binarySearch(int *b, int first, int last, int w)
//	{
//
//		if (first <= last){
//			int mid = first + (last - first) / 2;
//			if (b[mid] == w){
//				return mid;
//			}
//			else if (b[mid] < w){
//				return binarySearch(b, mid + 1, last, w);
//			}
//			else{
//				return binarySearch(b, first, mid - 1, w);
//			}
//		}
//		
//		return -1;
//	}
//	void binarySearchWithDup(int *b, int first, int last, int w)
//	{
//		int mid;
//		while (first <= last)
//		{
//			mid = first + (last - first) / 2;
//			if (b[mid] > w)
//				last = mid - 1;
//			else if (b[mid] < w)
//				first = mid + 1;
//			else    //找到了该元素，则直接返回  
//			{
//				int l = lbs(b, first, mid - 1, w);
//				if (l == -1){
//					l = mid;
//				}
//				cout << "left:" << l << endl;
//				int r = rbs(b, mid + 1, last, w);
//				
//				if (r == -1){
//					r = mid;
//				}
//				cout << "right:" << r << endl;
//				return;
//
//			}
//				
//		}
//		cout << "No the Num" << endl;//数组b中不存在该元素，则返回该元素应该插入的位置  
//	}
//	int lbs(int *b, int first, int last, int w)
//	{
//		int mid;
//		while (first <= last)
//		{
//			mid = first + (last - first) / 2;
//			if (b[mid] < w)
//				first = mid + 1;
//			else    //找到了该元素，则直接返回  
//			{
//				int l = lbs(b, first, mid - 1, w);
//				if (l == -1){
//					l = mid;
//				}
//				return l;
//			}
//
//		}
//		return -1;//数组b中不存在该元素，则返回该元素应该插入的位置  
//	}
//	int rbs(int *b, int first, int last, int w)
//	{
//		int mid;
//		while (first <= last)
//		{
//			mid = first + (last - first) / 2;
//			if (b[mid] > w)
//				last = mid - 1;
//			else    //找到了该元素，则直接返回  
//			{
//				int r = rbs(b, mid+1, last, w);
//				if (r == -1){
//					r = mid;	
//				}
//				return r;
//			}
//
//		}
//		return -1;//数组b中不存在该元素，则返回该元素应该插入的位置
//	}
//	void test(){
//		int a[] = { 1, 2, 3, 4, 4, 4, 5 };
//		binarySearchWithDup(a, 0, 6, 2);
//
//	}
//
//};