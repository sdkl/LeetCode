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
	int sumNumbers(TreeNode* root) {
		if (root == NULL) 
			return 0;

		if (root->left == NULL && root->right == NULL)
			return root->val;
		int newVal = root->val * 10;
		if (root->left != NULL)
			root->left->val += newVal;
		if (root->right != NULL)
			root->right->val += newVal;
		return sumNumbers(root->left) + sumNumbers(root->right);
	}
};

int main()
{
	Solution s;
	TreeNode node(1);
	TreeNode node2(2);
	TreeNode node3(3);
	node.left = &node2;
	node.right = &node3;
	cout << s.sumNumbers(&node) << endl;

	getchar();
	return 0;
}