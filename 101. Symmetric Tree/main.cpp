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
	bool isSymmetric(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == NULL || root2 == NULL)
			return root1 == root2;
		return root1->val == root2->val && isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
	}

	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		return isSymmetric(root->left, root->right);
	}
};

int main()
{
	Solution s;
	TreeNode head1(1);
	TreeNode head2(2);
	TreeNode head3(2);
	head1.left = &head2;
	head1.right = &head3;

	cout << s.isSymmetric(&head1) << endl;

	getchar();
	return 0;
}