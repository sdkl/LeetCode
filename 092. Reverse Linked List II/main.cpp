#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {	
		m--; n--;
		ListNode *normal1 = NULL, *reverse0 = NULL, *reverse1 = NULL, *last = NULL, *next = NULL;
		for (int i = 0; i <= n; i++)
		{
			if (i < m)
			{
				if (normal1 == NULL)
					normal1 = head;
				else
					normal1 = normal1->next;
			}				
			else if (i <= n)
			{
				if (i == m)
				{
					reverse0 = normal1 == NULL ? head : normal1->next;
					last = reverse1 = reverse0;
					next = reverse0 == NULL ? NULL : reverse0->next;
				}	
				else
				{
					reverse1 = next;
					next = reverse1->next;
					reverse1->next = last;
					last = reverse1;
					if (i == n)
						reverse0->next = next;
				}
			}
		}
		if (normal1 != NULL)
			normal1->next = reverse1;
		else
			head = reverse1;

		return head;
	}
};

int main()
{
	Solution s;
	int a[] = {1,2,3,4,5,6};
	ListNode *head,**cur = &head;
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		ListNode* n = new ListNode(a[i]);
		*cur = n;
		cur = &n->next;
	}

	head = s.reverseBetween(head, 1, 6);
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
		

	getchar();
	return 0;
}