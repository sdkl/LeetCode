#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *result = head,**cur = &result;
		while (cur != nullptr && (*cur) != nullptr)
		{
			while ((*cur) != nullptr && (*cur)->next != nullptr && (*cur)->val == (*cur)->next->val)
			{
				int v = (*cur)->val;
				while ((*cur) != nullptr && (*cur)->val == v)
				{
					*cur = (*cur)->next;
				}
			}
			cur = (*cur) == nullptr ? nullptr : &(*cur)->next;
		}
		return result;
	}
};

int main()
{
	Solution s;
	int arr[] = {1,2,3,3,4,4,5};
	ListNode head(arr[0]);
	ListNode** next = &head.next;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < len; i++)
	{
		ListNode* t = new ListNode(arr[i]);
		*next = t;
		next = &t->next;
	}
	ListNode* cur = s.deleteDuplicates(&head);
	while (cur != nullptr)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}

	getchar();
	return 0;
}