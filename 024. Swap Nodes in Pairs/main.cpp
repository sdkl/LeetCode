#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode *result = head->next == NULL ? head : head->next;

		ListNode *curNode = head, *nextNode = head->next;
		while (nextNode != NULL)
		{
			curNode->next = nextNode->next;
			nextNode->next = curNode;
			
			nextNode = curNode->next;
			if (nextNode != NULL && nextNode->next != NULL)
				curNode->next = nextNode->next;
			curNode = nextNode;
			nextNode = nextNode != NULL ? nextNode->next : NULL;
		}

		return result;
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
	ListNode *result = s.swapPairs(&a1);
	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}


	getchar();
	return 0;
}