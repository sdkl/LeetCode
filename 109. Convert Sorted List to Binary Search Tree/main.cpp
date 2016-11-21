#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<TreeNode*>& nums, int start, int end) {
		if (start > end)
			return NULL;
		int mid = (start + end) / 2;
		TreeNode* root = nums[mid];
		root->left = sortedArrayToBST(nums, start, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, end);
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		vector<TreeNode*> vct;
		while (head != NULL)
		{
			vct.push_back(new TreeNode(head->val));
			head = head->next;
		}

		return sortedArrayToBST(vct, 0, vct.size() - 1);
	}
};

void printTree(TreeNode* root, string space)
{
	if (root == NULL)
		return;

	printTree(root->right, space + " ");
	cout << space.c_str() << root->val << endl;
	printTree(root->left, space + " ");
}

int main()
{
	Solution s;
	vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	ListNode* head = NULL, **cur = &head;
	for (auto i : v)
	{
		ListNode* tmp = new ListNode(i);
		*cur = tmp;
		cur = &tmp->next;
	}

	TreeNode* r = s.sortedListToBST(head);

	printTree(r, "");

	getchar();
	return 0;
}