#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return NULL;
		int len = 1;
		ListNode* tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			len++;
		}		
		k %= len;
		if (k == 0)
			return head;
		tmp->next = head;		

		k = len - k;
		tmp = head;
		while (--k > 0)
			tmp = tmp->next;

		ListNode* result = tmp->next;
		tmp->next = NULL;

		return result;
	}
};

int main()
{
	Solution s;
	ListNode a1(1), a2(2), a3(3), a4(4), a5(5);
	a4.next = &a5;
	a3.next = &a4;
	a2.next = &a3;
	a1.next = &a2;

	ListNode* result = s.rotateRight(&a1, 2);

	while (result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}

	getchar();
	return 0;
}