#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		if (root->left == NULL && root->right == NULL)
			return sum == root->val;

		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

void printTree(TreeNode* root, string space)
{
	if (root == NULL)
		return;

	printTree(root->right, space + "  ");
	cout << space.c_str() << root->val << endl;
	printTree(root->left, space + "  ");
}

int main()
{
	Solution s;
	vector<int> tree = { 5, 4, 8, 11, 0, 13, 4, 7, 2 };
	vector<TreeNode*> treeV;
	TreeNode* head = new TreeNode(tree[0]), *cur;
	treeV.push_back(head);
	for (int i = 1; i < tree.size(); i++)
	{
		cur = tree[i] != 0 ? new TreeNode(tree[i]) : NULL;
		int p = (i - 1) / 2;
		if (treeV[p] != NULL)
			i%2 != 0 ? treeV[p]->left = cur : treeV[p]->right = cur;
		treeV.push_back(cur);
	}
	printTree(head,"");
	cout << s.hasPathSum(head,22) << endl;

	getchar();
	return 0;
}