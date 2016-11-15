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
	int max = 0;
	void depth(TreeNode* root,int d)
	{
		if (root == NULL)
			return;

		if (d > max) max = d;
		depth(root->left,d+1);
		depth(root->right,d+1);
	}

	int maxDepth(TreeNode* root) {
		depth(root, 1);
		return max;
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
	cout << s.maxDepth(&head1);

	getchar();
	return 0;
}