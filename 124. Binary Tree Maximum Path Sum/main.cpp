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
	int maxSum = INT_MIN;
	int maxPath(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int l = max(maxPath(root->left), 0);
		int r = max(maxPath(root->right), 0);
		maxSum = max(l + r + root->val, maxSum);

		return max(l, r) + root->val;
	}

	int maxPathSum(TreeNode* root) {
		maxPath(root);
		return maxSum;
	}
};


int main()
{
	Solution s;
	TreeNode h1(1);
	TreeNode h2(2);
	TreeNode h3(3);
	h1.left = &h2;
	h1.right = &h3;
	cout << s.maxPathSum(&h1);

	getchar();
	return 0;
}