#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* result = NULL,* curNode = NULL;

		while (l1 != NULL || l2 != NULL)
		{
			ListNode* newNode = NULL;
			bool l1val = l2 == NULL || (l1 != NULL && l1->val <= l2->val);
			newNode = new ListNode(l1val ? l1->val : l2->val);
			l1val ? l1 = l1->next : l2 = l2->next;

			if (curNode != NULL)
			{
				curNode->next = newNode;
				curNode = newNode;
			}
			else
			{
				curNode = newNode;
				result = curNode;
			}
		}

		return result;
	}
};


int main()
{
	ListNode a1(0);
	ListNode a2(2);
	ListNode a3(4);
	ListNode a4(6);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;

	ListNode b1(1);
	ListNode b2(3);
	ListNode b3(5);
	ListNode b4(7);
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &b4;

	Solution s;
	ListNode* result = s.mergeTwoLists(&a1, &b1);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}

	system("PAUSE");
	return 0;
}