#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;     
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* resultNode = NULL;
		ListNode* curResultNode = resultNode;
		ListNode* curNode1 = l1;
		ListNode* curNode2 = l2;
		
		int addUp = 0;

		while (curNode1 != NULL || curNode2 != NULL)
		{
			int val1 = curNode1 == NULL ? 0 : curNode1->val;
			int val2 = curNode2 == NULL ? 0 : curNode2->val;
			int curResult = val1 + val2 + addUp;
			addUp = curResult / 10;
			curResult %= 10;

			if (curResultNode == NULL)
			{
				resultNode = curResultNode = new ListNode(curResult);
			}
			else
			{
				curResultNode->next = new ListNode(curResult);
				curResultNode = curResultNode->next;
			}

			curNode1 = curNode1 == NULL ? NULL : curNode1->next;
			curNode2 = curNode2 == NULL ? NULL : curNode2->next;
		}

		if (addUp > 0)
		{
			curResultNode->next = new ListNode(addUp);
		}

		return resultNode;
	}
};

int main()
{
	Solution s;
	ListNode* list1 = new ListNode(2);
	list1->next = new ListNode(4);
	list1->next->next = new ListNode(3);


	ListNode* list2 = new ListNode(5);
	list2->next = new ListNode(6);
	list2->next->next = new ListNode(4);

	ListNode* result = s.addTwoNumbers(list1, list2);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}

	system("PAUSE");

	return 0;
}