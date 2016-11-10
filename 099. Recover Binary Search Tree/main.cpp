#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int i = 0;
	void traversal(TreeNode* root, vector<int>& all)
	{
		if (root == NULL)
			return;

		if (root->left != NULL)
			traversal(root->left, all);

		all.push_back(root->val);

		if (root->right != NULL)
			traversal(root->right, all);

	}

	void rTree(TreeNode* root, vector<int>& all)
	{
		if (root == NULL)
			return;

		if (root->left != NULL)
			rTree(root->left, all);

		root->val = all[i++];

		if (root->right != NULL)
			rTree(root->right, all);

	}

	void recoverTree(TreeNode* root) {
		vector<int> all;
		traversal(root, all);
		sort(all.begin(), all.end());
		rTree(root, all);
	}
};

void space(int n)
{
	for (int i = 0; i<n; i++)
		cout << ' ';
}

void printTree(TreeNode* t, int n)
{
	if (t == NULL)
		return;

	printTree(t->right, n + 2);
	space(n);
	cout << t->val << endl;
	printTree(t->left, n + 2);

}

int main()
{
	Solution s;
	TreeNode* head1 = new TreeNode(1);
	TreeNode* head2 = new TreeNode(2);
	TreeNode* head3 = new TreeNode(3);
	head1->left = head2;
	head1->right = head3;
	s.recoverTree(head1);

	printTree(head1, 0);

	getchar();
	return 0;
}