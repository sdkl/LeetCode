#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *p1 = head, *p2 = head;

		while (p2 != NULL && p2->next != NULL)
		{
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2)
			{
				p1 = head;
				while (p1 != p2)
				{
					p1 = p1->next;
					p2 = p2->next;
				}
				return p1;
			}
		}

		return NULL;
	}
};


int main()
{
	Solution s;
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a1;

	ListNode* node = s.detectCycle(&a1);
	cout << ((node == NULL) ? -1 : node->val )<< endl;

	getchar();
	return 0;
}