#include "common.h"

struct Node
{
	int val;
	Node* next;
	Node(int nval, Node* pNext)
		: val(nval)
		, next(pNext)
	{}
};
class Lianbiao
{
public:
	//创建链表
	Node* create(int num[], int length)
	{
		if (length <= 0){
			return NULL;
		}
		Node* head = new Node(num[0], NULL);;
		Node* cur = head;
		for (int i = 1; i < length; i++)
		{
			Node* temp = new Node(num[i], NULL);

			cur->next = temp;
			cur = cur->next;
		}
		return head;
	}
	
	//打印链表
	void print(Node* head)
	{
		while (head)
		{
			cout << head->val << " ";
			head = head->next;
		}
	}

	//链表的快速排序
	void quickSort(Node* begin, Node* end)
	{
		if (begin == NULL || begin->next == end)
		{
			return;
		}
		Node* index = partition(begin, end);
		if (begin != index){
			quickSort(begin, index);
		}
		if (index->next != end){
			quickSort(index->next, end);
		}

	}

	Node* partition(Node* begin, Node* end)
	{
		if (begin == NULL || begin->next == end)
		{
			return begin;
		}
		int key = begin->val;
		Node* small = begin;
		Node* cur = begin->next;
		while (cur != end)
		{
			if (cur->val < key){
				small = small->next;
				if (small != cur)
				{
					swap(small->val, cur->val);
				}
			}
			cur = cur->next;
		}
		swap(small->val, begin->val);
		return small;
	}


	//链表的归并排序
	Node *sortList(Node *head) {
		
	}

	//递归实现
	/*Node *merge(Node* h1, Node*h2)
	{
		if (h1 == NULL){
			return h2;
		}
		if (h2 == NULL){
			return h1;
		}
		Node *head;
		if (h1->val < h2->val){
			head = h1;
			head->next = merge(h1->next, h2);
		}
		else{
			head = h2;
			head->next = merge(h1, h2->next);
		}
		return head;
	}*/

	//非递归实现
	Node *merge(Node* h1, Node*h2)
	{
		if (h1 == NULL){
			return h2;
		}
		if (h2 == NULL){
			return h1;
		}
		Node *head, *tail;
		if (h1->val < h2->val){
			head = h1;
			h1 = h1->next;
		}
		else{
			head = h2;
			h2 = h2->next;
		}
		tail = head;

		while (h1 != NULL&&h2 != NULL){
			if (h1->val < h2->val){
				tail->next = h1;
				h1 = h1->next;
				
			}
			else{
				tail->next = h2;
				h2 = h2->next;
			}
			tail = tail->next;
		}
		if (h1 != NULL)
		{
			tail->next = h1;
			
		}
		if (h2 != NULL)
		{
			tail->next = h2;
			
		}
		
		return head;
	}

	void test()
	{
		int origin[] = { 21, 23, 3, 22, 57, 5 };
		int length = 4;
		Node *head = create(origin, 6);
		Node* end = head;
		for (int i = 0; i < length; i++){
			end = end->next;
		}
		quickSort(head,end);
		print(head);

	}
};

//int main()
//{
//	Lianbiao l;
//	l.test();
//}
