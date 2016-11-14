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
	void zigzagLevelOrder(TreeNode* root, int level, vector<vector<int>>& result)
	{
		if (root == NULL)
			return;

		if (result.size() <= level)
			result.push_back(vector<int>());
		result[level].push_back(root->val);

		zigzagLevelOrder(root->left, level + 1, result);
		zigzagLevelOrder(root->right, level + 1, result);
	}

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		zigzagLevelOrder(root, 0, result);
		for (int i = 1; i < result.size(); i += 2)
			reverse(result[i].begin(),result[i].end());
		return result;
	}
};

int main()
{
	Solution s;
	TreeNode head1(1);
	TreeNode head2(2);
	TreeNode head3(3);
	TreeNode head4(4);
	TreeNode head5(5);
	head1.left = &head2;
	head1.right = &head3;
	head3.left = &head4;
	head3.right = &head5;

	vector<vector<int>> r = s.zigzagLevelOrder(&head1);
	for (auto i : r)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	getchar();
	return 0;
}