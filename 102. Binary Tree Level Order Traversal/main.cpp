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
	void levelOrder(TreeNode* root, int level, vector<vector<int>>& result)
	{
		if (root == NULL)
			return;

		if (result.size() <= level)
			result.push_back(vector<int>());
		result[level].push_back(root->val);
		levelOrder(root->left, level + 1, result);
		levelOrder(root->right, level + 1, result);
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		levelOrder(root, 0, result);
		return result;
	}
};

int main()
{
	Solution s;
	TreeNode head1(1);
	TreeNode head2(2);
	TreeNode head3(3);
	head1.left = &head2;
	head2.right = &head3;

	vector<vector<int>> r = s.levelOrder(&head1);
	for (auto i : r)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	getchar();
	return 0;
}