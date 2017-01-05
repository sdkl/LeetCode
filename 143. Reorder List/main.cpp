#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		int nodeNum = 0;
		ListNode* cur = head;
		while (cur != NULL)
		{
			nodeNum++;
			cur = cur->next;
		}

		if (nodeNum < 3)
			return;

		ListNode *pre = head, *pos = head;
		int move = (nodeNum + 1) / 2;
		while (--move > 0)
			pos = pos->next;
		ListNode *tmp = pos->next;
		pos->next = NULL;
		pos = tmp;

		tmp = NULL;
		cur = pos;
		while (cur != NULL)
		{
			pos = cur;
			cur = pos->next;
			pos->next = tmp;
			tmp = pos;
		}

		while (pos != NULL)
		{
			tmp = pre->next;
			cur = pos->next;
			pre->next = pos;
			pos->next = tmp;
			pre = tmp;
			pos = cur;
		}
	}
};

int main()
{
	Solution s;
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *a3 = new ListNode(3);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;

	s.reorderList(a1);
	ListNode* n = a1;
	while (n != NULL)
	{
		cout << n->val << " ";
		n = n->next;
	}

	getchar();
	return 0;
}