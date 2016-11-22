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
	int getTreeDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int left = getTreeDepth(root->left);
		int right = getTreeDepth(root->right);

		if (left < 0 || right < 0 || abs(left - right) > 1)
			return -1;
		return left > right ? left + 1 : right + 1;
	}

	bool isBalanced(TreeNode* root) {
		return getTreeDepth(root) >= 0;
	}
};

void printTree(TreeNode* root, string s)
{
	if (root == NULL)
		return;
	printTree(root->right, s + " ");
	cout << s.c_str() << root->val << endl;
	printTree(root->left, s + " ");
}

int main()
{
	Solution s;
	vector<int> tree = { 1, 2, 2, 3, 0, 0, 3,4};
	vector<TreeNode*> treeV;
	TreeNode* head = NULL,*cur;
	for (int i = 0; i < tree.size(); i++)
	{
		if (tree[i] != 0)
		{
			cur = new TreeNode(tree[i]);
			if (head == NULL)
				head = cur;
		}			
		else
			cur = NULL;
		int p = (i - 1) / 2;
		if (p >= 0 && p < treeV.size() && treeV[p] != NULL)
		{
			if (p * 2 + 1== i)
				treeV[p]->left = cur;
			else
				treeV[p]->right = cur;
		}

		treeV.push_back(cur);
	}
	printTree(head, "");
	cout << s.isBalanced(head) << endl;

	getchar();
	return 0;
}