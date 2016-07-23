#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL)
			return head;

		ListNode* first = head;
		ListNode* scond = head;
		int i = 0;
		
		while (first->next != NULL)
		{
			if (i < n)
				i++;
			else
				scond = scond->next;
			first = first->next;
		}
		if (i < n)
			head = head->next;
		else
			scond->next = scond->next->next;

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
	ListNode* result = s.removeNthFromEnd(&a5,1);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
		

	system("PAUSE");
	return 0;
}