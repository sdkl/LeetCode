#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *tmp = head;
		int i = 0;
		for (; i < k && tmp != NULL; i++)
		{
			tmp = tmp->next;
		}

		if (i != k || k < 2)
			return head;

		int curStep = 2;
		ListNode **pHead = &head, *a = head, *b = head->next;
		while (a && b)
		{
			tmp = b->next;
			b->next = a;
			a = b;
			b = tmp;

			if (curStep++ == k)
			{
				(*pHead)->next = reverseKGroup(b, k);
				*pHead = a;
				break;
			}
		}

		return head;
	}
};


int main()
{
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;

	Solution s;
	ListNode *result = s.reverseKGroup(&a1,2);
	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}


	getchar();
	return 0;
}