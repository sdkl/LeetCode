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
	TreeNode* buildTree(vector<int>& inorder, int i1, int i2, vector<int>& postorder, int p1, int p2)
	{
		if (p1 >= p2)
			return NULL;
		int i = i1;
		while (i < i2 && inorder[i] != postorder[p2 - 1]) i++;
		i -= i1;
		TreeNode* root = new TreeNode(postorder[p2 - 1]);
		if (i > 0)
			root->left = buildTree(inorder, i1, i1 + i, postorder, p1, p1 + i);

		if (i1 + i + 1 < i2)
			root->right = buildTree(inorder, i1 + i + 1, i2, postorder, p1 + i, p2 - 1);

		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
};


void PrintTree(TreeNode *root, string s)
{
	if (root == NULL)
		return;
	PrintTree(root->right, s + " ");
	cout << s.c_str() << root->val << endl;
	PrintTree(root->left, s + " ");
}

int main()
{
	Solution s;
	vector<int> po = { 4, 5, 2, 6, 7, 3, 1 };
	vector<int> io = { 4, 2, 5, 1, 6, 3, 7 };
	TreeNode* r = s.buildTree(io,po);
	PrintTree(r, "");

	getchar();
	return 0;
}