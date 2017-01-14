#include<iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		ListNode left(0), right(0);
		ListNode *leftTail = &left, *rightTail = &right, *headTail = head;

		if (head != NULL)
		{
			ListNode *cur = head->next;
			while (cur != NULL)
			{
				if (cur->val < head->val)
				{
					leftTail->next = cur;
					leftTail = cur;
				}
				else if (cur->val > head->val)
				{
					rightTail->next = cur;
					rightTail = cur;
				}
				else
				{
					headTail->next = cur;
					headTail = cur;
				}
				cur = cur->next;
			}

			leftTail->next = rightTail->next = NULL;
			left.next = sortList(left.next);
			right.next = sortList(right.next);
			leftTail = &left;
			while (leftTail->next != NULL)
				leftTail = leftTail->next;
			leftTail->next = head;
			headTail->next = right.next;
		}

		return left.next;
	}
};

int main()
{
	Solution s;
	ListNode* a1 = new ListNode(1);
	ListNode* a2 = new ListNode(2);
	ListNode* a3 = new ListNode(3);
	a3->next = a2; a2->next = a1;
	ListNode *r = s.sortList(a3);
	while (r != NULL)
	{
		cout << r->val << " ";
		r = r->next;
	}

	getchar();
	return 0;
}