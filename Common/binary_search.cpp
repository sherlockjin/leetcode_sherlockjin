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
//			else    //�ҵ��˸�Ԫ�أ���ֱ�ӷ���  
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
//		cout << "No the Num" << endl;//����b�в����ڸ�Ԫ�أ��򷵻ظ�Ԫ��Ӧ�ò����λ��  
//	}
//	int lbs(int *b, int first, int last, int w)
//	{
//		int mid;
//		while (first <= last)
//		{
//			mid = first + (last - first) / 2;
//			if (b[mid] < w)
//				first = mid + 1;
//			else    //�ҵ��˸�Ԫ�أ���ֱ�ӷ���  
//			{
//				int l = lbs(b, first, mid - 1, w);
//				if (l == -1){
//					l = mid;
//				}
//				return l;
//			}
//
//		}
//		return -1;//����b�в����ڸ�Ԫ�أ��򷵻ظ�Ԫ��Ӧ�ò����λ��  
//	}
//	int rbs(int *b, int first, int last, int w)
//	{
//		int mid;
//		while (first <= last)
//		{
//			mid = first + (last - first) / 2;
//			if (b[mid] > w)
//				last = mid - 1;
//			else    //�ҵ��˸�Ԫ�أ���ֱ�ӷ���  
//			{
//				int r = rbs(b, mid+1, last, w);
//				if (r == -1){
//					r = mid;	
//				}
//				return r;
//			}
//
//		}
//		return -1;//����b�в����ڸ�Ԫ�أ��򷵻ظ�Ԫ��Ӧ�ò����λ��
//	}
//	void test(){
//		int a[] = { 1, 2, 3, 4, 4, 4, 5 };
//		binarySearchWithDup(a, 0, 6, 2);
//
//	}
//
//};