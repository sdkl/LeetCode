#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool init = false;
	int cur;
	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;

		if (!isValidBST(root->left))
			return false;

		if (!init)
		{
			init = true;			
		}
		else
		{
			if (cur >= root->val)
				return false;
		}
		cur = root->val;

		return isValidBST(root->right);
	}
};

int main()
{
	Solution s;
	TreeNode* head1 = new TreeNode(2);
	TreeNode* head2 = new TreeNode(1);
	TreeNode* head3 = new TreeNode(3);
	head1->left = head2;
	head1->right = head3;

	cout << s.isValidBST(head1) << endl;

	getchar();
	return 0;
}