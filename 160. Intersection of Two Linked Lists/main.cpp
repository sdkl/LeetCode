#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
	  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;

		ListNode* p1 = headB, *p2 = headB, *tail = headA, *tail2 = headB;
		while (tail->next != NULL)
			tail = tail->next;
		while (tail2->next != NULL)
			tail2 = tail2->next;

		if (tail == tail2)
		{
			tail->next = headA;
			while (p2 != NULL && p2->next != NULL)
			{
				p1 = p1->next;
				p2 = p2->next->next;
				if (p1 == p2)
					break;
			}
			
			p1 = headB;
			while (p1 != p2)
			{
				p1 = p1->next;
				p2 = p2->next;
			}

			tail->next = NULL;
			return p1;
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
	ListNode b1(4);
	ListNode b2(5);
	ListNode b3(6);
	ListNode b4(7);
	ListNode c1(8);
	ListNode c2(9);
	ListNode c3(10);
	ListNode c4(11);
	ListNode c5(12);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &c1;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &b4;
	b4.next = &c1;
	c1.next = &c2;
	c2.next = &c3;
	c3.next = &c4;
	c4.next = &c5;

	ListNode *r = s.getIntersectionNode(&a1,&b1);
	if (r != NULL)
		cout << r->val << endl;
	else
		cout << "NULL" << endl;

	getchar();
	return 0;
}