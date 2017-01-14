#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* result = NULL,*tmp = NULL,*next = NULL;

		while (head != NULL)
		{
			next = head->next;
			if (result == NULL)
			{
				result = head;
				result->next = NULL;
			}				
			else
			{
				if (head->val <= result->val)
				{
					head->next = result;
					result = head;
				}
				else
				{
					tmp = result;
					while (tmp->next != NULL && tmp->next->val < head->val)
						tmp = tmp->next;
					head->next = tmp->next;
					tmp->next = head;
				}				
			}

			head = next;
		}

		return result;
	}
};

int main()
{
	Solution s;
	ListNode* a1 = new ListNode(1);
	ListNode* a2 = new ListNode(2);
	ListNode* a3 = new ListNode(3);
	a3->next = a2; a2->next = a1;
	ListNode* r = s.insertionSortList(a3);
	while (r != NULL)
	{
		cout << r->val << " ";
		r = r->next;
	}

	getchar();
	return 0;
}