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
	TreeNode* buildTree(vector<int>& preorder,int p1,int p2, vector<int>& inorder,int i1,int i2)
	{
		if (p1 == p2)
			return NULL;
		int i = i1;
		while (i < i2 && inorder[i] != preorder[p1]) i++;
		i -= i1;
		TreeNode* root = new TreeNode(preorder[p1]);
		if (i > 0)
			root->left = buildTree(preorder, p1 + 1, p1 + i + 1, inorder, i1, i1 + i);

		if (i1 + i + 1 < i2)
			root->right = buildTree(preorder, p1 + i + 1, p2, inorder, i1 + i + 1, i2);

		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder,0,preorder.size(), inorder,0,inorder.size());
	}
};


void PrintTree(TreeNode *root,string s)
{
	if (root == NULL)
		return;
	PrintTree(root->right, s + " ");
	cout<< s.c_str() << root->val << endl;
	PrintTree(root->left, s + " ");
}

int main()
{
	Solution s;
	vector<int> po = {1,2,4,5,3,6,7};
	vector<int> io = {4,2,5,1,6,3,7};
	TreeNode* r = s.buildTree(po, io);
	PrintTree(r, "");

	getchar();
	return 0;
}