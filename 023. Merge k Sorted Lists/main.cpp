#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* result = NULL,* curNode1,* curNode2,* tmpNode;
		
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i] == NULL)
				continue;

			if (result == NULL)
			{
				result = lists[i];
				continue;
			}

			curNode1 = result->val <= lists[i]->val ? result : lists[i];
			curNode2 = result->val > lists[i]->val ? result : lists[i];
			result = curNode1;

			while (true)
			{
				while (curNode1->next != NULL && curNode1->next->val <= curNode2->val) 
					curNode1 = curNode1->next;

				if (curNode1->next == NULL)
				{
					curNode1->next = curNode2;
					break;
				}					
				else
				{
					tmpNode = curNode1->next;
					curNode1->next = curNode2;					
					curNode1 = curNode2;
					curNode2 = tmpNode;
				}
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

	ListNode c1(1);
	ListNode c2(3);
	ListNode c3(5);
	ListNode c4(7);
	c1.next = &c2;
	c2.next = &c3;
	c3.next = &c4;

	vector<ListNode*> lists;
	lists.push_back(NULL);
	lists.push_back(&a1);
	lists.push_back(&b1);
	lists.push_back(&c1);

	Solution s;
	ListNode* result = s.mergeKLists(lists);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}

	system("PAUSE");
	return 0;
}