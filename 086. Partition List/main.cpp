#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *l1 = NULL, *l2 = NULL, **cl1 = &l1, **cl2 = &l2;
		while (head != NULL)
		{
			if (x > head->val)
			{
				*cl1 = head;
				cl1 = &head->next;
			}
			else
			{
				*cl2 = head;
				cl2 = &head->next;
			}
			head = head->next;
		}
		if (l1 != NULL)
			*cl1 = l2;
		*cl2 = NULL;
		return l1 == NULL ? l2 : l1;
	}
};

int main()
{
	Solution s;
	int a[] = { 1, 4, 3, 2, 5, 2 };
	ListNode *head,**cur = &head;
	int len = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < len; i++)
	{
		*cur = new ListNode(a[i]);
		cur = &(*cur)->next;
	}

	head = s.partition(NULL, 3);
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}	

	getchar();
	return 0;
}