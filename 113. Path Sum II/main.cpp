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
	void pathSum(vector<vector<int>>& result,vector<int>& cur, TreeNode* root, int sum)
	{
		if (root == NULL)
			return;
		cur.push_back(root->val);

		if (root->left == NULL && root->right == NULL)
		{
			if (sum == root->val)
				result.push_back(cur);
		}
		pathSum(result, cur, root->left, sum - root->val);
		pathSum(result, cur, root->right, sum - root->val);
		cur.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> cur;

		pathSum(result, cur , root, sum);
		return result;
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
	vector<int> tree = { 5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 0, 0, 5, 1 };
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
	vector<vector<int>> r = s.pathSum(head, 22);
	for (auto i : r)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	getchar();
	return 0;
}