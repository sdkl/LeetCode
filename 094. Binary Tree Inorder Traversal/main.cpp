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
	void itraversal(vector<int>& result, TreeNode* root)
	{
		if (root == NULL)
			return;

		if (root->left != NULL)
			itraversal(result, root->left);

		result.push_back(root->val);

		if (root->right != NULL)
			itraversal(result, root->right);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		itraversal(result, root);
		return result;
	}
};

int main()
{
	Solution s;
	TreeNode* head = new TreeNode(1);
	TreeNode* c1 = new TreeNode(2);
	TreeNode* c2 = new TreeNode(3);
	head->right = c1;
	c1->left = c2;
	vector<int> r = s.inorderTraversal(head);
	for (auto i : r)
		cout << i << " ";

	getchar();
	return 0;
}