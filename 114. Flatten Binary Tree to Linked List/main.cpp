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
	TreeNode* flat(TreeNode* root)
	{
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return root;

		TreeNode* l = flat(root->left);
		TreeNode* r = flat(root->right);
		if (l != NULL)
		{
			l->right = root->right;
			root->right = root->left;
		}		
		root->left = NULL;

		return r == NULL ? l : r;
	}

	void flatten(TreeNode* root) {
		flat(root);
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
	vector<int> tree = { 1,2,5,3,4,0,6 };
	vector<TreeNode*> treeV;
	TreeNode* head = new TreeNode(tree[0]), *cur;
	treeV.push_back(head);
	for (int i = 1; i < tree.size(); i++)
	{
		cur = tree[i] != 0 ? new TreeNode(tree[i]) : NULL;
		int p = (i - 1) / 2;
		if (treeV[p] != NULL)
			i % 2 != 0 ? treeV[p]->left = cur : treeV[p]->right = cur;
		treeV.push_back(cur);
	}

	printTree(head, "");
	s.flatten(head);
	cout << endl;
	printTree(head, "");

	getchar();
	return 0;
}